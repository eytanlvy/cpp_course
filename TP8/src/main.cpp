#include "../includes/vecteur.hpp"
#include "../includes/triangle.hpp"

int main() {
	Vecteur v1(1, 2);
	Vecteur v2(1, 2);
	Vecteur v3(3, 4);
	std::cout << (v1 == v2) << std::endl;
	std::cout << (v1 != v2) << std::endl;
	std::cout << (v1 == v3) << std::endl;
	std::cout << (v1 != v3) << std::endl;

	std::cout << (v1 + v2) << std::endl;
	std::cout << (v1 - v3) << std::endl;
	std::cout << (v2 * v3) << std::endl;
	v2[1] = 5;
	std::cout << v3 << std::endl;

	Triangle t1(v1, v2, v3);
	t1.test();
	return 0;
}