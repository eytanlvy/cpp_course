#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include "trigo.hpp"

double autreCote(double const angle, char c = 'r', double const longueur)
{
	return (sinus(angle, c) * longueur);
}