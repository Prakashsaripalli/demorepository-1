package com.booking.backend.dao;

import com.booking.backend.model.OtpRecord;
import com.booking.backend.utils.JdbcUtil;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.atomic.AtomicBoolean;

public class OtpDao {

    private static final ConcurrentHashMap<String, OtpRecord> FALLBACK_STORE = new ConcurrentHashMap<>();
    private static final AtomicBoolean FALLBACK_WARNED = new AtomicBoolean(false);

    public void saveOtp(String mobile, String otp, long expiryMillis) {
        long expiresAt = System.currentTimeMillis() + expiryMillis;
        String sql = """
                INSERT INTO otps(mobile, otp, expires_at, created_at)
                VALUES (?, ?, ?, CURRENT_TIMESTAMP)
                ON DUPLICATE KEY UPDATE otp = VALUES(otp), expires_at = VALUES(expires_at), created_at = CURRENT_TIMESTAMP
                """;
        try (Connection conn = JdbcUtil.getConnection();
             PreparedStatement ps = conn.prepareStatement(sql)) {
            ps.setString(1, mobile);
            ps.setString(2, otp);
            ps.setLong(3, expiresAt);
            ps.executeUpdate();
        } catch (SQLException e) {
            warnFallback("OTP save", e);
            FALLBACK_STORE.put(mobile, new OtpRecord(mobile, otp, expiresAt));
        }
    }

    public boolean verifyOtp(String mobile, String otp) {
        String selectSql = "SELECT otp, expires_at FROM otps WHERE mobile = ?";
        try (Connection conn = JdbcUtil.getConnection();
             PreparedStatement selectPs = conn.prepareStatement(selectSql)) {
            selectPs.setString(1, mobile);

            try (ResultSet rs = selectPs.executeQuery()) {
                if (!rs.next()) {
                    return false;
                }

                long expiresAt = rs.getLong("expires_at");
                String storedOtp = rs.getString("otp");

                if (System.currentTimeMillis() > expiresAt) {
                    deleteOtp(conn, mobile);
                    return false;
                }

                boolean matched = otp.equals(storedOtp);
                if (matched) {
                    deleteOtp(conn, mobile);
                }
                return matched;
            }
        } catch (SQLException e) {
            warnFallback("OTP verify", e);
            return verifyFallbackOtp(mobile, otp);
        }
    }

    private void deleteOtp(Connection conn, String mobile) throws SQLException {
        try (PreparedStatement deletePs = conn.prepareStatement("DELETE FROM otps WHERE mobile = ?")) {
            deletePs.setString(1, mobile);
            deletePs.executeUpdate();
        }
    }

    private boolean verifyFallbackOtp(String mobile, String otp) {
        OtpRecord record = FALLBACK_STORE.get(mobile);
        if (record == null) {
            return false;
        }

        if (System.currentTimeMillis() > record.getExpiresAt()) {
            FALLBACK_STORE.remove(mobile);
            return false;
        }

        boolean matched = otp.equals(record.getOtp());
        if (matched) {
            FALLBACK_STORE.remove(mobile);
        }
        return matched;
    }

    private void warnFallback(String action, SQLException e) {
        if (FALLBACK_WARNED.compareAndSet(false, true)) {
            System.err.println("[Warning] " + action + " falling back to in-memory store due to DB error.");
        }
        e.printStackTrace();
    }
}
