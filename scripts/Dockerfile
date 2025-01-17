FROM alpine:3.16
LABEL maintainer "wanxpgm@gmail.com"
ARG THREADS="10"
ARG SHA=""

# build minimized
WORKDIR /
RUN apk add --no-cache --virtual .build-tools git g++ build-base linux-headers cmake
RUN apk add --no-cache --virtual .build-deps curl-dev rapidjson-dev libevent-dev pcre2-dev yaml-cpp-dev 
RUN git clone https://github.com/ftk/quickjspp --depth=1 && \
    cd quickjspp && \
    git submodule update --init && \
    cmake -DCMAKE_BUILD_TYPE=Release . && \
    make quickjs -j $THREADS && \
    install -m644 quickjs/libquickjs.a /usr/lib && \
    install -d /usr/include/quickjs/ && \
    install -m644 quickjs/quickjs.h quickjs/quickjs-libc.h /usr/include/quickjs/ && \
    install -m644 quickjspp.hpp /usr/include && \
    cd /
RUN git clone https://github.com/PerMalmberg/libcron --depth=1 && \
    cd libcron && \
    git submodule update --init && \
    cmake -DCMAKE_BUILD_TYPE=Release . && \
    make libcron -j $THREADS && \
    install -m644 libcron/out/Release/liblibcron.a /usr/lib/ && \
    install -d /usr/include/libcron/ && \
    install -m644 libcron/include/libcron/* /usr/include/libcron/ && \
    install -d /usr/include/date/ && \
    install -m644 libcron/externals/date/include/date/* /usr/include/date/ && \
    cd /
RUN git clone https://github.com/ToruNiina/toml11 --depth=1 && \
    cd toml11 && \
    cmake . && \
    make install -j $THREADS && \
    cd /
RUN git clone https://github.com/Wanxp/subconverter-extend --depth=1 && \
    cd subconverter-extend && \
    cmake -DCMAKE_BUILD_TYPE=Release . && \
    make -j $THREADS && \
    mv subconverter /usr/bin && \
    mv base ../ && \
    cd /
RUN rm -rf subconverter-extend quickjspp libcron toml11 /usr/lib/lib*.a /usr/include/* /usr/local/include/lib*.a /usr/local/include/* && \
    apk add --no-cache --virtual subconverter-deps pcre2 libcurl yaml-cpp libevent && \
    apk del .build-tools .build-deps

# set entry
WORKDIR /base
CMD subconverter

