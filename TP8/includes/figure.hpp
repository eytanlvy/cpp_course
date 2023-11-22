#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <iostream>
#include "vecteur.hpp"

class Figure {
	protected:
		std::string nom;
	public:
		Figure(std::string n): nom(n) {}
		std::string const get_nom() const {
			return this->nom;
		}
		virtual void perimetre() const = 0;
		virtual double area() const = 0;
		virtual void test() const = 0;

		virtual ~Figure() {}
};
#endif