FROM debian:bullseye

RUN apt update && apt dist-upgrade -y

RUN apt install -y\
    git\
    cmake\
    automake\
    build-essential\
    pkg-config\
    libx11-dev\
    libxcb-keysyms1-dev\
    python3.9-dev\
    libqt5svg5-dev\
    libqt5x11extras5-dev\
    libpcre2-dev\
    libpcre++-dev\
    libx11-xcb-dev\
    libxrandr-dev\
    libxinerama-dev\
    libxcursor-dev\
    libxi-dev\
    xvfb

RUN mkdir -p /src

WORKDIR /src
RUN git clone https://github.com/baldurk/renderdoc.git

WORKDIR /src/renderdoc
RUN git checkout v1.18 && mkdir -p /src/renderdoc/build

WORKDIR /src/renderdoc/build
RUN cmake ../ && make
