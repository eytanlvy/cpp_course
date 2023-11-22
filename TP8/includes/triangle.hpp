#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <iostream>
#include "figure.hpp"
#include "vecteur.hpp"

class Triangle : public Figure {
	private:
		Vecteur a;
		Vecteur b;
		Vecteur c;
	public:
		Triangle(Vecteur a, Vecteur b, Vecteur c);
		Vecteur const get_a() const {
			return this->a;
		}
		Vecteur const get_b() const {
			return this->b;
		}
		Vecteur const get_c() const {
			return this->c;
		}
		void perimetre() const override ;
		double area() const override ;
		void test() const override ;
};
std::ostream& operator<<( std::ostream &out , const Triangle &x );

#endif