FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y \
    build-essential \
    libx11-dev \
    libxext-dev \
    libbsd-dev \
    zlib1g-dev \
    gcc \
    make \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /app
COPY . .
RUN chmod +x libs/mlx_linux/configure
RUN make
CMD ["./fdf", "maps/42.fdf"]