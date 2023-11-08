CPP=g++ --std=c++11 -Wall

all : projet

projet : projet.o
	$(CPP) -o projet projet.o

projet.o : projet.cpp
	$(CPP) -c projet.cpp

clean :
	rm *.o

fclean : clean
	rm projet