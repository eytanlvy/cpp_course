#ifndef cell_hpp
#define cell_hpp

#include <iostream>
using namespace std;

class Cell
{
	private:
		int data;
		Cell *next;
		Cell *prev;
	public:
		Cell (int d, Cell *n, Cell *p);
		Cell (int d);
		friend void connect (Cell *first, Cell *second);
		void connect (Cell *new_next);
		void disconnectNext();
		void disconnectPrev();
		int getData() const { return data; };
		void setData(int d) { data = d; };
		Cell *getNext() const { return next; };   //todo: implement setters to prevent from modifying the getters
		Cell *getPrev() const { return prev; };
		virtual ~Cell();
};



ostream& operator<<( ostream &out , const Cell &x );




#endif