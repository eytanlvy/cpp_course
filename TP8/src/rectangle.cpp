#include "../includes/rectangle.hpp"

Rectangle::Rectangle(Vecteur a, Vecteur c): Quadrilatere(a, Vecteur(a.get_x(), c.get_y()), c, Vecteur(c.get_x(), a.get_y())){
	std::cout << "Naissance de " << *this << std::endl;
}

void Rectangle::perimetre() const{
	double p = 2*(this->get_a() - this->get_b()).norm() + 2*(this->get_b() - this->get_c()).norm();	
	std::cout << "Perimetre de " << *this << " = " << p << std::endl;
}

double Rectangle::area() const{
	double p = (this->get_a() - this->get_b()).norm() * (this->get_b() - this->get_c()).norm();
	return std::abs(p);
}

void Rectangle::test() const {
	std::cout << "Test de " << *this << std::endl;
	this->perimetre();
	double ar = this->area();
	std::cout << "Aire de " << *this << " = " << ar << std::endl;
}

std::ostream& operator<<( std::ostream &out , const Rectangle &x ) {
	out << x.get_nom() << "(" << x.get_a() << ", " << x.get_b() << ", " << x.get_c() << ", " << x.get_d() << ")";
	return out;
}