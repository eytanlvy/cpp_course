#include <iostream>

int plus(int a, int b) {
    return a + b;
}

double plus(double a, double b) {
    return a + b;
}

int main() {
    int intResult;
    double doubleResult;

    // Utilisation de la version int de la fonction plus
    intResult = plus(5, 3);
    std::cout << "Addition d'entiers : " << intResult << std::endl;

    // Utilisation de la version double de la fonction plus
    doubleResult = plus(2.5, 3.7);
    std::cout << "Addition de double : " << doubleResult << std::endl;

	float a = 6;
	float b = 10;
	float floatResult;
	floatResult = plus(a, b);
    std::cout << "Addition de float : " << floatResult << std::endl;

    return 0;
}
