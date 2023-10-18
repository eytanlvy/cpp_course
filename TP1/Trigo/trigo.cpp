#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>

double sinus(double const x, char const c = 'r')
{
	if (c == 'r') {
		return sin(x);
	} else if (c == 'd') {
		return sin(M_PI * x / 180);
	} else if (c == 'g') {
		return sin(M_PI * x / 200);
	} else {
		return (-1);
	}
}

int main() {
	std::cout << "sinus(PI / 2) = " << sinus(M_PI / 2) << std::endl;
}