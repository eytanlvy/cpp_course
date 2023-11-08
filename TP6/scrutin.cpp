#include "scrutin.hpp"

Scrutin::Scrutin(int nb_urnes) : nb_urnes(nb_urnes), fini(false) {
	for (int i = 0; i < nb_urnes; i++) {
		Urne * urne = new Urne(*this);
		urnes.push_back(urne);
	}
	std::cout<< "Scrutin créé: (" << nb_urnes << " urnes)" << std::endl;
}

int const Scrutin::get_nb_urnes() const {
	return nb_urnes;
}

std::vector<Urne *> const Scrutin::get_urnes() const {
	return urnes;
}

int const Scrutin::get_fini() const {
	return fini;
}

void Scrutin::finir() {
	fini = true;
}

Scrutin::~Scrutin() {
	for (int i = 0; i < urnes.size(); i++) {
		delete urnes[i];
	}
	std::cout << "Scrutin détruit" << std::endl;
}

void Scrutin::resultat() const {
	if (!fini) {
		std::cout << "Scrutin non terminé" << std::endl;
		return;
	}
	std::vector<int> votes (3,0);
	for (int i = 0; i < urnes.size(); i++) {
		for (const Choix& vote : urnes[i]->get_votes()) {
			if (vote == Choix::Oui)
				votes[0]++;
			else if (vote == Choix::Non)
				votes[1]++;
			else
				votes[2]++;
		}
	}
	
	int max = 0;
	for (int i = 0; i < votes.size(); i++) {
		if (votes[i] > max) {
			max = votes[i];
		}
	}
	std::cout << "Résultat du scrutin: " << std::endl;
	for (int i = 0; i < votes.size(); i++) {
		if (votes[0] == max) {
			std::cout << "Option Oui gagnante avec " << votes[i] << " voix" << std::endl;
		} else if (votes[1] == max) {
			std::cout << "Option Non gagnante avec " << votes[i] << " voix" << std::endl;
		} else {
			std::cout << "Option Blanc gagnante avec " << votes[i] << " voix" << std::endl;
		}
	}
}