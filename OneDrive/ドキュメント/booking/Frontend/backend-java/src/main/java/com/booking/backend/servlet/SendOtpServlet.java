package com.booking.backend.servlet;

import com.booking.backend.dao.OtpDao;
import com.booking.backend.model.SendOtpRequest;
import com.booking.backend.utils.EmailUtil;
import com.booking.backend.utils.JsonUtil;
import com.booking.backend.utils.OtpGenerator;
import com.booking.backend.utils.ResponseUtil;
import com.booking.backend.utils.ValidationUtil;
import jakarta.mail.MessagingException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class SendOtpServlet extends HttpServlet {

    private final OtpDao otpDao;

    public SendOtpServlet(OtpDao otpDao) {
        this.otpDao = otpDao;
    }

    @Override
    protected void doOptions(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        ResponseUtil.json(resp, HttpServletResponse.SC_OK, Map.of("success", true));
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        SendOtpRequest payload = JsonUtil.mapper().readValue(req.getInputStream(), SendOtpRequest.class);
        String mobile = payload.mobile == null ? "" : payload.mobile.trim();
        String email = payload.email == null ? "" : payload.email.trim().toLowerCase();
        boolean devOtpEnabled = isDevOtpEnabled();

        if (mobile.isEmpty() && email.isEmpty()) {
            ResponseUtil.json(resp, HttpServletResponse.SC_BAD_REQUEST, Map.of(
                    "success", false,
                    "message", "Either mobile or email is required"
            ));
            return;
        }

        if (!email.isEmpty()) {
            if (!ValidationUtil.isValidEmail(email)) {
                ResponseUtil.json(resp, HttpServletResponse.SC_BAD_REQUEST, Map.of(
                        "success", false,
                        "message", "Invalid email address"
                ));
                return;
            }

            String otp = OtpGenerator.generateSixDigitOtp();
            final long expiry = 5 * 60 * 1000L;

            try {
                otpDao.saveOtp(email, otp, expiry);
                String smtpError = EmailUtil.smtpConfigError();
                if (smtpError != null) {
                    if (devOtpEnabled) {
                        ResponseUtil.json(resp, HttpServletResponse.SC_OK, Map.of(
                                "success", true,
                                "emailSent", false,
                                "message", smtpError + " (dev OTP: " + otp + ")"
                        ));
                    } else {
                        ResponseUtil.json(resp, HttpServletResponse.SC_INTERNAL_SERVER_ERROR, Map.of(
                                "success", false,
                                "message", smtpError
                        ));
                    }
                    return;
                }
                EmailUtil.sendOtpEmail(email, otp);
                ResponseUtil.json(resp, HttpServletResponse.SC_OK, Map.of(
                        "success", true,
                        "message", "OTP sent to email. Check Inbox/Spam/Promotions."
                ));
            } catch (RuntimeException e) {
                e.printStackTrace();
                ResponseUtil.json(resp, HttpServletResponse.SC_INTERNAL_SERVER_ERROR, Map.of(
                        "success", false,
                        "message", "Failed to save OTP. Check database settings."
                ));
            } catch (MessagingException e) {
                e.printStackTrace();
                String errorMessage = e.getMessage() == null || e.getMessage().isBlank()
                        ? "Failed to send OTP email. Check SMTP settings."
                        : "Failed to send OTP email: " + e.getMessage();
                if (devOtpEnabled) {
                    ResponseUtil.json(resp, HttpServletResponse.SC_OK, Map.of(
                            "success", true,
                            "emailSent", false,
                            "message", errorMessage + " (dev OTP: " + otp + ")"
                    ));
                } else {
                    ResponseUtil.json(resp, HttpServletResponse.SC_INTERNAL_SERVER_ERROR, Map.of(
                            "success", false,
                            "message", errorMessage
                    ));
                }
            }
            return;
        }

        if (!ValidationUtil.isValidMobile(mobile)) {
            ResponseUtil.json(resp, HttpServletResponse.SC_BAD_REQUEST, Map.of(
                    "success", false,
                    "message", "Invalid mobile. Expected format +91XXXXXXXXXX"
            ));
            return;
        }

        String otp = OtpGenerator.generateSixDigitOtp();
        final long expiry = 5 * 60 * 1000L;

        try {
            otpDao.saveOtp(mobile, otp, expiry);
        } catch (RuntimeException e) {
            e.printStackTrace();
            ResponseUtil.json(resp, HttpServletResponse.SC_INTERNAL_SERVER_ERROR, Map.of(
                    "success", false,
                    "message", "Failed to save OTP. Check database settings."
            ));
            return;
        }

        Map<String, Object> response = new HashMap<>();
        response.put("success", true);
        response.put("message", "OTP sent to mobile");
        ResponseUtil.json(resp, HttpServletResponse.SC_OK, response);
    }

    private boolean isDevOtpEnabled() {
        String raw = System.getenv("OTP_DEV_MODE");
        if (raw == null || raw.isBlank()) {
            return false;
        }
        String normalized = raw.trim().toLowerCase();
        return normalized.equals("true") || normalized.equals("1") || normalized.equals("yes") || normalized.equals("y");
    }
}
