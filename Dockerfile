FROM ubuntu:20.04

RUN apt-get update && apt-get install -y \
    build-essential \
    libssl-dev \
    zlib1g-dev 

RUN mkdir -p /app

COPY . /app

WORKDIR /app

RUN make -j /app

CMD ./build/bin/transit_service 8081 apps/transit_service/web/