#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include <iostream>

class Vecteur {
	private:
		double x;
		double y;
	public:
		Vecteur(double x, double y);
		bool operator==(const Vecteur& rv) const;
		bool operator!=(const Vecteur& rv) const;
		Vecteur operator+(const Vecteur& rv) const;
		Vecteur operator-(const Vecteur& rv) const;
		double operator*(const Vecteur& rv) const;
		double& operator[](const int i);
		double norm() const;
		double const get_x() const {
			return this->x;
		}
		double const get_y() const {
			return this->y;
		}
};
std::ostream& operator<<( std::ostream &out , const Vecteur &x );

#endif