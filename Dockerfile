FROM ubuntu:22.04
LABEL maintainer="AstroCat"
LABEL description="Dockerfile for setting up a development environment for *Tiny C Projects*"

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    bash \
    build-essential \
    cmake \
    curl \
    wget \
    git \
    vim \
    ca-certificates \
	clang \
    clang-format \
	lld \
	lldb

RUN curl -sS https://starship.rs/install.sh | sh -s -- -y && \
    echo 'eval "$(starship init bash)"' >> ~/.bashrc

RUN rm -rf /var/lib/apt/lists/*

WORKDIR /work

COPY . .

CMD ["/bin/bash"]
