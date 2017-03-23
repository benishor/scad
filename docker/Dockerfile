FROM benishor/mxe-qt5
MAINTAINER Adrian Scripca <benishor@gmail.com>

ENV PATH /work/mxe/usr/bin:$PATH
VOLUME /work/project

COPY build.sh /build.sh
RUN chmod +x /build.sh

ENTRYPOINT ["/build.sh"] 