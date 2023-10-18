#include "horloge.hpp"
int fh(int i) {
	if (i <= 0) {
		return 0;
	}
	return i / 3600;
}
int fm(int i) {
	if (i <= 0) {
		return 0;
	}
	return (i % 3600) / 60;
}

int fs(int i) {
	if (i <= 0) {
		return 0;
	}
	return (i % 3600) % 60;
}

Horloge::Horloge (int h, int m, int s) : heures{fh(h * 3600 + m * 60 + s)}, minutes{fm(h * 3600 + m * 60 + s)}, secondes{fs(h * 3600 + m * 60 + s)}
{
	cout<<"Nouvelle horloge créée!" <<endl;
};

ostream& operator<<(ostream &out ,const Horloge&x ) {
	out << x.getHeures() << ":" << x.getMinutes() << ":" << x.getSecondes() << endl ;
	return out ;
}

Horloge::~Horloge() {
	cout << "Horloge détruite: " << *this;
}

void Horloge::tick() {
	cout << "Tick: il est "<< *this << "+ 1 seconde"<< endl;
	this->setSecondes(this->getSecondes() + 1);
	if (this->getSecondes() >= 60) {
		this->setSecondes(0);
		this->setMinutes(this->getMinutes() + 1);
		if (this->getMinutes() >= 60) {
			this->setMinutes(0);
			this->setHeures(this->getHeures() + 1);
			if (this->getHeures() >= 24) {
				this->setHeures(0);
				cout << "Jour suivant: il est "<< *this << endl;
			}
		}
	} 
}

Horloge::Horloge (const Horloge & x): heures{x.heures} , minutes{x.minutes} , secondes{x.secondes} {
	cout << "Naissance d'une copie de "<< *this << endl;
}

int main() {
	int heure;
	int minute;
	int seconde;

	std::cout << "Heure? (0-23)";
	std::cin >> heure; 
	std::cout << "Minute? (0-59)"; 
	std::cin >> minute; 
	std::cout << "Seconde? (0-59)";
	std::cin >> seconde;

	Horloge h(heure, minute, seconde);
	cout<<h;
	h.tick();
	cout<<h;

}