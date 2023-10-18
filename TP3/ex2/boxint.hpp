#ifndef _BOXINT
#define _BOXINT

#include <iostream>
#include <ctime>
using namespace std;

class BoxInt
{
	private:
		int data { 0 };
		static int count;
		time_t last;
	public:
		BoxInt(int d);
		int get();
		void set(int d);
		time_t getLast() const;
		static int alive_count();
		virtual ~BoxInt();
};

ostream& operator<<( ostream &out , const BoxInt &x );

#endif