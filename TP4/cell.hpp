#ifndef cell_hpp
#define cell_hpp

#include <iostream>
using namespace std;

class Cell
{
	friend class List;

	private:
		int data;
		Cell *next;
		Cell *prev;

		void connect (Cell *new_next);
		void disconnectNext();
		void disconnectPrev();
		void setData(int d) { data = d; };
		void setNext(Cell *n) { next = n; };
		void setPrev(Cell *p) { prev = p; };

		Cell (int d, Cell *n, Cell *p);
		Cell (int d);
	public:
		int const getData() const { return data; };
		Cell * const getNext() const { return next; };
		Cell * const getPrev() const { return prev; };
		virtual ~Cell();
};



ostream& operator<<( ostream &out , const Cell &x );




#endif