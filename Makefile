CXX = g++
CPPFLAGS = -Iinclude
CXXFLAGS = -std=c++14 -Wall -g  -Llib 
LDFLAGS = -Llib
LDLIBS = -lsdl2 -lsdl2_image 
OBJECTS = main.o game.o texturemanager.o loaderparams.o gameobject.o sdlgameobject.o player.o 
DEPENDS = ${OBJECTS:.o=.d}
EXEC = pong.o

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${LDFLAGS} ${CPPFLAGS} ${LDLIBS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
