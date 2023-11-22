#include "../includes/vecteur.hpp"

Vecteur::Vecteur(double x, double y): x(x), y(y) {
	std::cout << "Naissance du vecteur " << *this << std::endl;
}

std::ostream& operator<<( std::ostream &out , const Vecteur &x ) {
	out << "(" << x.get_x() << ", " << x.get_y() << ")";
	return out;
}

bool Vecteur::operator==(const Vecteur& rv) const {
	return this->x == rv.x && this->y == rv.y;
}

bool Vecteur::operator!=(const Vecteur& rv) const {
	return !(*this == rv);
}

Vecteur Vecteur::operator+(const Vecteur& rv) const {
	return Vecteur(this->x + rv.x, this->y + rv.y);
}

Vecteur Vecteur::operator-(const Vecteur& rv) const {
	return Vecteur(this->x - rv.x, this->y - rv.y);
}

double Vecteur::operator*(const Vecteur& rv) const {
	return this->x * rv.x + this->y * rv.y;
}

double& Vecteur::operator[](const int i) {
	if (i == 0) {
		return this->x;
	} else if (i == 1) {
		return this->y;
	} else {
        throw std::invalid_argument( "try 0 or 1 in input" );
	}
}

double Vecteur::norm() const {
	return sqrt(this->x * this->x + this->y * this->y);
}

