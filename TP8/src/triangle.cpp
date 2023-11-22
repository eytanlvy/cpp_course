#include "../includes/triangle.hpp"

Triangle::Triangle(Vecteur a, Vecteur b, Vecteur c): Figure("Triangle"), a(a), b(b), c(c) {
	std::cout << "Naissance de " << *this << std::endl;
}

std::ostream& operator<<( std::ostream &out , const Triangle &x ) {
	out << x.get_nom() << "(" << x.get_a() << ", " << x.get_b() << ", " << x.get_c() << ")";
	return out;
}

void Triangle::perimetre() const{
	double p = (this->a - this->b).norm() + (this->b - this->c).norm() + (this->c - this->a).norm();	
	std::cout << "Perimetre de " << *this << " = " << p << std::endl;
}

double Triangle::area() const{
	double p = a.get_x() * (b.get_y() - c.get_y()) + b.get_x() * (c.get_y() - a.get_y()) + c.get_x() * (a.get_y() - b.get_y());
	return std::abs(p) / 2;
}

void Triangle::test() const {
	std::cout << "Test de " << *this << std::endl;
	this->perimetre();
	std::cout << "Aire de " << *this << " = " << this->area() << std::endl;
}