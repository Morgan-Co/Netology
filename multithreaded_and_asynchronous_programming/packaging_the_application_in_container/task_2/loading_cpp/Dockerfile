FROM ubuntu:20.04

RUN apt update && apt install -y g++ clang cmake make

WORKDIR /app

COPY . .

RUN mkdir build_gcc && cd build_gcc && cmake .. -DCMAKE_CXX_COMPILER=g++ && make
RUN mkdir build_clang && cd build_clang && cmake .. -DCMAKE_CXX_COMPILER=clang++ && make

CMD ["/app/build_gcc/loading_cpp"]
