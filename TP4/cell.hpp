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
		int const getData() const { return data; };
		void setData(int d) { data = d; };
		Cell * const getNext() const { return next; };
		void setNext(Cell *n) { next = n; };
		Cell * const getPrev() const { return prev; };
		void setPrev(Cell *p) { prev = p; };
		virtual ~Cell();
};



ostream& operator<<( ostream &out , const Cell &x );




#endif