CPP=g++ --std=c++11 -Wall

all : cell

cell : cell.o
	$(CPP) -o cell cell.o

cell.o : cell.cpp
	$(CPP) -c cell.cpp

clean :
	rm *.o

fclean : clean
	rm cell