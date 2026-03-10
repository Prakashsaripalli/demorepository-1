package com.booking.backend.dao;

import com.booking.backend.model.PaymentRecord;
import com.booking.backend.utils.JdbcUtil;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.time.Instant;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.UUID;

public class PaymentDao {

    private static final ConcurrentHashMap<String, PaymentRecord> FALLBACK_STORE = new ConcurrentHashMap<>();
    private static final AtomicBoolean FALLBACK_WARNED = new AtomicBoolean(false);

    public synchronized PaymentRecord save(String passengerName, String mobile, String email, int amount, String transactionId) {
        String normalizedTransactionId = normalizeTransactionId(transactionId);

        if (existsByTransactionId(normalizedTransactionId)) {
            throw new IllegalStateException("Transaction ID already used");
        }

        PaymentRecord record = new PaymentRecord(
                UUID.randomUUID().toString(),
                passengerName,
                mobile,
                email,
                amount,
                normalizedTransactionId,
                "SUCCESS",
                Instant.now().toString()
        );

        String sql = """
                INSERT INTO payments(payment_id, passenger_name, mobile, email, amount, transaction_id, status, created_at)
                VALUES (?, ?, ?, ?, ?, ?, ?, ?)
                """;
        try (Connection conn = JdbcUtil.getConnection();
             PreparedStatement ps = conn.prepareStatement(sql)) {
            ps.setString(1, record.getPaymentId());
            ps.setString(2, record.getPassengerName());
            ps.setString(3, record.getMobile());
            ps.setString(4, record.getEmail());
            ps.setInt(5, record.getAmount());
            ps.setString(6, record.getTransactionId());
            ps.setString(7, record.getStatus());
            ps.setString(8, record.getCreatedAt());
            ps.executeUpdate();
        } catch (SQLException e) {
            warnFallback("Payment save", e);
            FALLBACK_STORE.put(normalizedTransactionId, record);
        }
        return record;
    }

    private boolean existsByTransactionId(String transactionId) {
        String sql = """
                SELECT 1
                FROM payments
                WHERE transaction_id = ?
                LIMIT 1
                """;
        try (Connection conn = JdbcUtil.getConnection();
             PreparedStatement ps = conn.prepareStatement(sql)) {
            ps.setString(1, transactionId);
            return ps.executeQuery().next();
        } catch (SQLException e) {
            warnFallback("Payment check", e);
            return FALLBACK_STORE.containsKey(transactionId);
        }
    }

    private String normalizeTransactionId(String transactionId) {
        return transactionId == null ? "" : transactionId.trim().replaceAll("\\s+", "").toUpperCase();
    }

    private void warnFallback(String action, SQLException e) {
        if (FALLBACK_WARNED.compareAndSet(false, true)) {
            System.err.println("[Warning] " + action + " falling back to in-memory store due to DB error.");
        }
        e.printStackTrace();
    }
}
