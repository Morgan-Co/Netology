FROM ubuntu:16.04

RUN apt update && apt install -y gcc

COPY hello.c /hello.c 

RUN gcc /hello.c -o /hello

CMD ["/hello"]
