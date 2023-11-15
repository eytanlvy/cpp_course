#include "../includes/caddie.hpp"

Caddie::Caddie() {
	std::cout << "Naissance du Caddie " << *this << std::endl;
}

std::vector<Article*> const& Caddie::get_articles() const{
	return articles;
}

void Caddie::ajoute(Article &a) {
	articles.push_back(&a);
}

std::ostream& operator<<(std::ostream& out, const Caddie &x) {
    for (const Article* article : x.get_articles()) {
        out << "[" << *article << "]" << std::endl;
    }
    return out;
}

Caddie::~Caddie() {
	std::cout << "Mort de Caddie "<< std::endl;
}