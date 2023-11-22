#include "../includes/quadrilatere.hpp"

Quadrilatere::Quadrilatere(Vecteur a, Vecteur b, Vecteur c, Vecteur d): Figure("Quadrilatere"), a(a), b(b), c(c), d(d) {
	std::cout << "Naissance de " << *this << std::endl;
}

std::ostream& operator<<( std::ostream &out , const Quadrilatere &x ) {
	out << x.get_nom() << "(" << x.get_a() << ", " << x.get_b() << ", " << x.get_c() << ", " << x.get_d() << ")";
	return out;
}