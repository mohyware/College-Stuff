FROM python:3.9-slim
WORKDIR /app
COPY node.py /app/node.py
# Use -u to make python output unbuffered, so docker logs show prints instantly
ENTRYPOINT ["python", "-u", "node.py"]
