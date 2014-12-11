CC=gcc
SOURCES = hellomp3.c
CFLAGS = `pkg-config gstreamer-1.0 --cflags`
LIBS = `pkg-config gstreamer-1.0 --libs`
EXECUTABLE = hellomp3
all:
	${CC} ${SOURCES} ${CFLAGS} -o ${EXECUTABLE} ${LIBS}
clean:
	${RM} ${EXECUTABLE}
