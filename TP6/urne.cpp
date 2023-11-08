#include "urne.hpp"

static int n = 0;

Urne::Urne(Scrutin& scrutin) : scrutin(scrutin) {
	num = n;
	n++;
	std::cout << "Urne " << num << " créée" << std::endl;
}

Scrutin& Urne::get_scrutin() const {
	return scrutin;
}

int const Urne::get_num() const {
	return num;
}

std::vector<Choix> const Urne::get_votes() const {
	return votes;
}

bool Urne::voter(Choix choix)
{
	votes.push_back(choix);
	return true;
}

Urne::~Urne() {
	std::cout << "Urne " << num << " détruite" << std::endl;
}

std::ostream& operator<<( std::ostream &out , const Urne &x ) {
	out << "Urne " << x.get_num() << " : ";
	if (!x.get_scrutin().get_fini())
		return out << "scrutin non terminé";
	
	for (int i = 0; i < x.get_votes().size(); i++) {
		out << x.get_votes()[i] << " ";
	}
	return out;
}