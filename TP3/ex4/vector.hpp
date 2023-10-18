#ifndef _VECTOR
#define _VECTOR

#include <iostream>
using namespace std;

class Vector
{
	private:
		int *data;
		int size;
	public:
		Vector(int *data, int s);
		virtual ~Vector();
		int * get_data() const;
		int get_size() const;
};

ostream& operator<<( ostream &out , const Vector &x );

#endif