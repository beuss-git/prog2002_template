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
    xvfb\
    vim\
    python3\
    python3-pip

RUN mkdir -p /src

WORKDIR /src
RUN git clone https://github.com/baldurk/renderdoc.git

WORKDIR /src/renderdoc
RUN git checkout v1.18 && mkdir -p /src/renderdoc/build

WORKDIR /src/renderdoc/build
RUN cmake ../ -DENABLE_VULKAN=OFF -DENABLE_QRENDERDOC=OFF -DENABLEPYRENDERDOC=OFF && make -j8 && make install


WORKDIR /src
RUN mkdir -p /src/template/
ADD ./ /src/template/
WORKDIR /src/template
RUN git submodule update --init --recursive && mkdir -p /src/template/build

WORKDIR /src/template/build
RUN cmake ../ && make -j8


WORKDIR /src

# Export and enable xvfb display
COPY Docker/init_xvfb.sh /src/init_xvfb.sh
RUN chmod +x /src/init_xvfb.sh
ARG RESOLUTION="1024x1024x24"
ENV XVFB_RES="${RESOLUTION}"
ARG XARGS=""
ENV XVFB_ARGS="${XARGS}"
ENV DISPLAY=":99"
ENTRYPOINT ["/bin/sh", "/src/init_xvfb.sh"]

# Quick access to ctest
WORKDIR /src/template/build/external/tester