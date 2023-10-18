CPP = g++ -std=c++11 -Wall
OBJS = cell.o list.o  # Liste de tous les fichiers objets nécessaires

all: cell

cell: $(OBJS)
	$(CPP) -o cell $(OBJS)

cell.o: cell.cpp
	$(CPP) -c cell.cpp

list.o: list.cpp
	$(CPP) -c list.cpp

clean:
	rm -f *.o

fclean: clean
	rm -f cell
