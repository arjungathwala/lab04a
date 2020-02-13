# lab04a by Eric Buckland

CXX=clang++
# CXX=g++

# We have -Wno-unused-parameter so that the compiler
# doesn't complain too much about our stubs.

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

BINARIES=lab04Test

all: ${BINARIES}

tests: ${BINARIES}
	./lab04Test	

lab04Test: lab04Test.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@
	

	
clean:
	/bin/rm -f ${BINARIES} *.o
