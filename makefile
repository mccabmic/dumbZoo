CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g


OBJS = Animal.o Source.o Tiger.o Cage.o Zoo.o Penguin.o Turtle.o
SRCS = Animal.cpp Source.cpp Tiger.cpp Cage.cpp Zoo.cpp Penguin.cpp Turtle.cpp
HEADERS = Animal.hpp Tiger.hpp Cage.hpp Zoo.hpp Penguin.hpp Turtle.hpp

Zoo: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o Zoo

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: 
	rm -f ${OBJS}
	rm -f Zoo
