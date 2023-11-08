#ifndef SCRUTIN_HPP
#define SCRUTIN_HPP

#include "urne.hpp"
#include "choix.hpp"
#include "vector"
#include <iostream>

class Urne;
class Scrutin {
	private:
		int nb_urnes;
		bool fini;
		std::vector <Urne *> urnes;
	public:
		Scrutin (int nb_urnes);
		int const get_nb_urnes() const;
		int const get_fini() const;
		void finir();
		std::vector <Urne *> const get_urnes() const;
		void resultat() const;
		virtual ~Scrutin();
};
#endif