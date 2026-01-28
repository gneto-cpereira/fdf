FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    make \
    libx11-dev \
    libxext-dev \
    zlib1g-dev \
    libbsd-dev \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /app
COPY . .
RUN make
CMD ["./fdf", "maps/42.fdf"]