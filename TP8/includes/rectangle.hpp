#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>
#include "figure.hpp"
#include "vecteur.hpp"
#include "quadrilatere.hpp"

class Rectangle: public Quadrilatere {
	public:
		Rectangle(Vecteur a, Vecteur b);
		void perimetre() const override ;
		double area() const override ;
		void test() const override ;
};
std::ostream& operator<<( std::ostream &out , const Rectangle &x );

#endif