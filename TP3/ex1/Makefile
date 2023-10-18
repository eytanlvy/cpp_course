CPP=g++ --std=c++11 -Wall

all : horloge

horloge : horloge.o
	$(CPP) -o horloge horloge.o

horloge.o : horloge.cpp
	$(CPP) -c horloge.cpp

clean :
	rm *.o

fclean : clean
	rm horloge