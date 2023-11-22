#ifndef QUADRILATERE_HPP
#define QUADRILATERE_HPP

#include <iostream>
#include "figure.hpp"
#include "vecteur.hpp"

class Quadrilatere: public Figure {
	private:
		Vecteur a;
		Vecteur b;
		Vecteur c;
		Vecteur d;
	public:
		Quadrilatere(Vecteur a, Vecteur b, Vecteur c, Vecteur d);
		Vecteur const get_a() const {
			return this->a;
		}
		Vecteur const get_b() const {
			return this->b;
		}
		Vecteur const get_c() const {
			return this->c;
		}
		Vecteur const get_d() const {
			return this->d;
		}
};
std::ostream& operator<<( std::ostream &out , const Quadrilatere &x );

#endif