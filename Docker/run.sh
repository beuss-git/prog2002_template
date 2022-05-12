#!/bin/bash
cd ..
# Remove the old container
docker rm -f template
# Build container
docker build --build-arg cores=1 -f Docker/Dockerfile -t template .
# Start container
docker run -it -d --name template template /bin/sh
