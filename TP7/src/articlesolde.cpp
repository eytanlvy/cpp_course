#include "../includes/articlesolde.hpp"

ArticleEnSolde::ArticleEnSolde(std::string nom, double prix, int remise) : Article(nom, prix), remise(remise) {
	std::cout << "Naissance de " << *this << std::endl;
}

ArticleEnSolde::ArticleEnSolde(Article const& a, int remise):  Article(a), remise(remise){
	std::cout << "Naissance de " << *this << " (copy constructor) " << std::endl;
}

ArticleEnSolde::~ArticleEnSolde() {
	std::cout << "Mort de " << *this << std::endl;
}

double const ArticleEnSolde::get_prix() const {
	return prix * (1 - remise / 100.0);
}
