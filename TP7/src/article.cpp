#include "../includes/article.hpp"

Article::Article(std::string n, double p) : nom(n), prix(p) {
	std::cout << "Naissance de " << *this << std::endl;
}

Article::Article(Article const& a) : nom(a.nom), prix(a.prix) {
	std::cout << "Naissance de " << *this << std::endl;
}

Article::~Article() {
	std::cout << "Mort de " << *this << std::endl;
}

std::string const Article::get_nom() const {
	return nom;
}

double const Article::get_prix() const {
	return prix;
}

std::string Article::toString() const {
	return nom + ", " + std::to_string(get_prix()) + "€";
}

std::ostream& operator<<( std::ostream &out , const Article &x ) {
	out << x.toString();
	return out;
}