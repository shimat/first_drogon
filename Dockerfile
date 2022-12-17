FROM ubuntu:22.04

ENV TZ=Asia/Tokyo

# https://drogon.docsforge.com/master/installation/#library-dependencies
RUN apt-get update && apt install -y \
  git \
  gcc \
  g++ \
  cmake \
  libjsoncpp-dev \
  uuid-dev \
  openssl \
  libssl-dev \
  zlib1g-dev

RUN git clone https://github.com/drogonframework/drogon && \
  cd drogon && \
  git submodule update --init && \
  mkdir build && \
  cd build && \
  cmake .. && \
  make && make install
