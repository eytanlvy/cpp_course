#include "scrutin.hpp"
#include <iostream>

int main()
{
	Scrutin scrutin(3);
	std::vector<Urne *> urnes = scrutin.get_urnes();
	for (int i = 0; i < urnes.size(); i++) {
		std::cout << "Urne " << urnes[i]->get_num() << std::endl;
	}

	//votes

	urnes[0]->voter(Oui);
	urnes[0]->voter(Non);
	urnes[1]->voter(Non);
	urnes[1]->voter(Non);
	urnes[1]->voter(Blanc);
	urnes[2]->voter(Non);
	urnes[2]->voter(Non);
	urnes[2]->voter(Oui);

	for (int i = 0; i < urnes.size(); i++) {
		std::cout << *urnes[i] << std::endl;
	}

	std::cout << "Scrutin terminé" << std::endl;
	scrutin.finir();
	for (int i = 0; i < urnes.size(); i++) {
		std::cout << *urnes[i] << std::endl;
	}

	scrutin.resultat();
	return 0;
}