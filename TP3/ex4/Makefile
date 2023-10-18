CPP=g++ --std=c++11 -Wall

all : vector

vector : vector.o
	$(CPP) -o vector vector.o

vector.o : vector.cpp
	$(CPP) -c vector.cpp

clean :
	rm *.o

fclean : clean
	rm vector