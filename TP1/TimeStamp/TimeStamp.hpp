#ifndef _TIMESTAMP
#define _TIMESTAMP

#include <iostream>
using namespace std;

#define NULL __null

class Timestamp {
	private:
		int hour;
		int minute;
		int second;
	public:
		Timestamp(int a, int b, int c);
		int getHour() const;
		void setHour(int h);
		int getMinute() const;
		void setMinute(int m);
		int getSecond() const;
		void setSecond(int s);
};

#endif