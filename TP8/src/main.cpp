#include "../includes/vecteur.hpp"
#include "../includes/triangle.hpp"
#include "../includes/quadrilatere.hpp"
#include "../includes/rectangle.hpp"

int main() {
	Vecteur v1(1, 2);
	Vecteur v2(-1, -1);
	Vecteur v3(3, 4);
	Vecteur v4(5, 6);
	Triangle t1(v1, v2, v3);
	t1.test();

	Rectangle r1(v1, v2);
	r1.test();
	return 0;
}