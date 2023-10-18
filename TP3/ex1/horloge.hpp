#ifndef _HORLOGE
#define _HORLOGE

#include <iostream>
using namespace std;

class Horloge {
	private:
		int heures{0};
		int minutes{0};
		int secondes{0};
	public:
		Horloge(int h, int m, int s);
		int getHeures() const { return heures; };
		int getMinutes() const { return minutes; };
		int getSecondes() const { return secondes; };
		void setHeures(int h) { heures = h; };
		void setMinutes(int m) { minutes = m; };
		void setSecondes(int s) { secondes = s; };
		void tick();
		Horloge (const Horloge&);
		virtual ~Horloge();
};

ostream& operator<<( ostream &out , const Horloge &x );
#endif