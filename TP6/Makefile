CPP = g++ -std=c++11 -Wall
OBJS = urne.o scrutin.o main.o choix.o

all: urne

urne: $(OBJS)
	$(CPP) -o urne $(OBJS)

urne.o: urne.cpp
	$(CPP) -c urne.cpp

scrutin.o: scrutin.cpp
	$(CPP) -c scrutin.cpp

main.o: main.cpp
	$(CPP) -c main.cpp

choix.o: choix.cpp
	$(CPP) -c choix.cpp

clean:
	rm -f *.o

fclean: clean
	rm -f urne
