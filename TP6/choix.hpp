#ifndef CHOIX_HPP
#define CHOIX_HPP

#include <iostream>

enum Choix {
	Oui,
	Non,
	Blanc,
};

std::ostream& operator<<(std::ostream& out, const Choix& choix);

#endif