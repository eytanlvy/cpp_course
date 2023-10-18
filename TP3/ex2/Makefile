CPP=g++ --std=c++11 -Wall

all : boxint

boxint : boxint.o
	$(CPP) -o boxint boxint.o

boxint.o : boxint.cpp
	$(CPP) -c boxint.cpp

clean :
	rm *.o

fclean : clean
	rm boxint