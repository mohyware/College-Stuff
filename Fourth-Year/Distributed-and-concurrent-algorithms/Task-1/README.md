# Docker Task

This is A simple Express.js application containerized with Docker running on Node.js.

I have also used Docker in deploying a side project Packet meter (Cross-platform network traffic monitoring system so it can be self-hosted easily).
here is the repo https://github.com/mohyware/packet-meter

## Setup & Run

### 1. Build the Docker Image

Uses `node:18-alpine` as the base image (small ~50MB LTS image). Dependencies are copied and installed before source code to maximise Docker layer caching — `npm install` is only re-run when `package.json` changes.

```bash
docker build -t express-node-app .
```

### 2. Run the Container

**Production / normal run:**
```bash
docker run -d -p 3000:3000 --name node-container express-node-app
```

**Development mode with hot-reload (volume mount):**
```bash
docker run --name node-container \
  -v "$(pwd):/app" \
  -v /app/node_modules \
  -d -p 3000:3000 express-node-app
```

- `-v "$(pwd):/app"` — mounts your local project folder into the container so file changes are instantly visible inside it.
- `-v /app/node_modules` — anonymous volume that protects the container's `node_modules` from being overwritten by the host mount.
- `nodemon --legacy-watch` runs inside the container and auto-restarts Node whenever a file changes. No rebuild needed.

### 3. Access Your App

Open your browser or run:

```bash
curl http://localhost:3000
```

You should see: **Mohy Server!**

### 4. Useful Commands

```bash
# Open a shell inside the running container
docker exec -it node-container sh

# View container logs
docker logs node-container

# Stop and remove the container
docker stop node-container && docker rm node-container

# Remove the image
docker rmi express-node-app
```