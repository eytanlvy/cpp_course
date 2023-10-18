#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
using namespace std;
#include "cell.hpp"

class List
{
	private:
		Cell *first;
		Cell *last;
	public:
		List ();
		virtual ~List();
		int length() const;
		int get(int idx);
		int find(int val);
		void set(int idx, int val);
		void insert(int idx, int val);
		void del(int idx);
		Cell * const getFirst() const { return first; };
		void setFirst(Cell *f) { first = f; };
		Cell * const getLast() const { return last; };
		void setLast(Cell *l) { last = l; };
};
ostream& operator<<( ostream &out , const List &x );

#endif