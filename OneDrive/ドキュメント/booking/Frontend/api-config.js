(function attachYubusApiConfig(window, document) {
    function normalizeBase(value) {
        const trimmed = String(value || "").trim();
        if (!trimmed) {
            return "";
        }

        return trimmed.replace(/\/+$/, "");
    }

    function getSameOriginBase() {
        const origin = normalizeBase(window.location.origin);
        if (!origin || origin === "null") {
            return "";
        }

        if (/^file:/i.test(window.location.protocol)) {
            return "";
        }

        return origin;
    }

    function buildUrl(path, base) {
        const normalizedPath = String(path || "").startsWith("/") ? String(path) : `/${String(path || "")}`;
        const normalizedBase = normalizeBase(base);
        return normalizedBase ? `${normalizedBase}${normalizedPath}` : normalizedPath;
    }

    const metaBase = normalizeBase(document.querySelector('meta[name="yubus-api-base"]')?.content);
    const globalBase = normalizeBase(window.YUBUS_API_BASE);
    const fallbackBases = [
        globalBase,
        metaBase,
        getSameOriginBase(),
        "http://localhost:8081",
        "http://127.0.0.1:8081",
        "http://localhost:8080",
        "http://127.0.0.1:8080"
    ].filter(Boolean);
    const bases = [...new Set(fallbackBases)];

    window.YUBUS_API = Object.freeze({
        getBases() {
            return [...bases];
        },
        buildUrl,
        describeTarget() {
            return metaBase || globalBase || getSameOriginBase() || "the configured backend";
        }
    });
}(window, document));
