CC=gcc
SOURCES = singlemp3play.c
CFLAGS = `pkg-config gstreamer-1.0 --cflags`
LIBS = `pkg-config gstreamer-1.0 --libs`
EXECUTABLE = cmdmp3
all:
	${CC} ${SOURCES} ${CFLAGS} -o ${EXECUTABLE} ${LIBS}
clean:
	${RM} ${EXECUTABLE}
