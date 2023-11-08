#ifndef URNE_HPP
#define URNE_HPP

#include "scrutin.hpp"
#include "choix.hpp"
#include <iostream>

class Scrutin;
class Urne {
	friend class Scrutin;
	private:
		Scrutin& scrutin;
		int num;
		std::vector <Choix> votes;
		bool * fini_ptr;
		Urne (Scrutin& scrutin);
		virtual ~Urne();

	public:
		Scrutin& get_scrutin() const;
		int const get_num() const;
		std::vector <Choix> const get_votes() const;
		bool voter(Choix choix);
};

std::ostream& operator<<( std::ostream &out , const Urne &x );

#endif