#ifndef CADDIE_HPP
#define CADDIE_HPP

#include "article.hpp"
#include <vector>

class Caddie {
	private:
		std::vector<Article*> articles;

	public:
		Caddie();
		std::vector<Article*> const& get_articles() const; 
		void ajoute(Article &a);
		virtual ~Caddie();
};
std::ostream& operator<<( std::ostream &out , const Caddie &x );

#endif
