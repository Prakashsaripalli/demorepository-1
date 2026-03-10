# Yubus Deployment

This project can be published publicly, but the frontend and backend need to be deployed separately unless you serve them from the same host.

## GitHub Pages + Render

This repo now includes:

- [`.github/workflows/deploy-pages.yml`](./.github/workflows/deploy-pages.yml) to publish the frontend from the `main` branch
- [`render.yaml`](./render.yaml) to create the Java backend service on Render

### 1. GitHub Pages frontend

The frontend is static HTML/CSS/JS, so it can be hosted on:

- GitHub Pages
- Netlify
- Vercel
- Cloudflare Pages

For GitHub Pages in this repo:

1. In GitHub, open `Settings > Pages` and set `Source` to `GitHub Actions`.
2. In GitHub, open `Settings > Secrets and variables > Actions > Variables`.
3. Create a repository variable named `YUBUS_API_BASE`.
4. Set it to your Render backend URL, for example `https://yubus-backend.onrender.com`.

The workflow injects that value into the existing frontend meta tag:

```html
<meta name="yubus-api-base" content="https://your-backend.example.com">
```

If the frontend and backend are served from the same origin, leave that meta tag empty and the app will use the current site origin automatically.

### 2. Render backend

Deploy `backend-java` on a Java host such as:

- Render
- Railway
- Fly.io
- Any VPS with Java 17 and MySQL

Required environment variables:

```text
PORT=8081
DB_URL=jdbc:mysql://<host>:3306/booking?createDatabaseIfNotExist=true&useSSL=false&allowPublicKeyRetrieval=true&serverTimezone=UTC
DB_USER=<your-db-user>
DB_PASSWORD=<your-db-password>
ALLOWED_ORIGIN=https://your-frontend.example.com
SMTP_USER=<gmail-address>
SMTP_APP_PASSWORD=<gmail-app-password>
SMTP_FROM=<gmail-address>
```

For Render with this repo:

1. Create a new Blueprint service in Render and point it to this repository.
2. Render will read [`render.yaml`](./render.yaml).
3. Set the unsynced environment variables in the Render dashboard.
4. Set `ALLOWED_ORIGIN` to your GitHub Pages URL, for example `https://prakashsaripalli.github.io/demorepository-1`.

Build and run:

```bash
mvn clean package
java -jar target/backend-java-1.0.0.jar
```

### 3. Important limits

- User accounts and some booking state are still stored in browser `localStorage`, so each device/browser keeps its own local session data.
- Real payment gateways are not integrated; the payment screen is still a simulated flow.
- You still need a real MySQL database and SMTP credentials for public use.
