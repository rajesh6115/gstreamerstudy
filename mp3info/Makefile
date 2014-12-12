CXX=g++
SOURCES = getmp3info.cpp
CFLAGS = `pkg-config taglib --cflags`
LIBS = `pkg-config taglib --libs`
EXECUTABLE = mp3info
all:
	${CXX} ${SOURCES} ${CFLAGS} -o ${EXECUTABLE} ${LIBS}
clean:
	${RM} ${EXECUTABLE}
