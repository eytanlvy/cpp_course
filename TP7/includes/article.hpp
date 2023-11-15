#ifndef ARTICLE_HPP
#define ARTICLE_HPP

#include<iostream>

class Article {
	protected:
		std::string nom;
		double prix;
	public:
		Article(std::string n, double p);
		Article(Article const& a);
		virtual ~Article();
		std::string const get_nom() const;
		virtual double const get_prix() const;
		std::string toString() const;
};
std::ostream& operator<<( std::ostream &out , const Article &x );


#endif