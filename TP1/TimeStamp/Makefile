CPP=g++ --std=c++11 -Wall

all : test

test : test.o
	$(CPP) -o test test.o

test.o : test.cpp
	$(CPP) -c test.cpp

clean :
	rm *.o