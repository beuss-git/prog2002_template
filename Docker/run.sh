#!/bin/bash
cd ..
# Remove the old container
docker rm -f template
# Build container
docker build -f Docker/Dockerfile -t template .
# Start container
docker run -it -d --name template template /bin/sh
