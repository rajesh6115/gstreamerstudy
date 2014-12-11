CC=gcc
SOURCES = hello.c
CFLAGS = `pkg-config gstreamer-1.0 --cflags`
LIBS = `pkg-config gstreamer-1.0 --libs`
EXECUTABLE = hello
all:
	${CC} ${SOURCES} ${CFLAGS} -o ${EXECUTABLE} ${LIBS}
clean:
	${RM} ${EXECUTABLE}
