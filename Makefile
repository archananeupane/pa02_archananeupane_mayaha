#Makefile
CXX_FLAG = --std=c++11 -g
all: runMovies tests

runMoviescpps: movies.cpp main.cpp movies.h
	g++ $(CXX_FLAG) movies.cpp main.cpp -c

runMovies: movies.o main.o
	g++ $(CXX_FLAG) movies.o main.o -o runMovies

testscpps: tests.cpp movies.cpp tests.h movies.h
	g++ $(CXX_FLAG) tests.cpp movies.cpp -c

tests: tests.o movies.o
	g++ $(CXX_FLAG) tests.o movies.o -o tests

clean:
	rm runMovies tests