#ifndef ARTICLESOLDE_HPP
#define ARTICLESOLDE_HPP

#include "article.hpp"

class ArticleEnSolde : public Article {
	private:
		int remise;
	public:
		ArticleEnSolde(std::string nom, double prix, int remise);
		ArticleEnSolde(Article const& a, int remise = 0);
		virtual ~ArticleEnSolde();
		virtual double const get_prix() const;
};
#endif