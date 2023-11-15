#include "../includes/article.hpp"
#include "../includes/articlesolde.hpp"
#include "../includes/caddie.hpp"

using namespace std;

int main() {

Article a1("Parapluie", 12);
cout << a1 << endl;
ArticleEnSolde a2("Botte",12,5);
cout << a2 << endl;
ArticleEnSolde a3(a1);
cout << a3 << endl;
ArticleEnSolde a4 = a1;
cout << a4 << endl;

Caddie c;
c.ajoute(a1);
c.ajoute(a2);
c.ajoute(a3);
c.ajoute(a4);
cout << c << endl;

return 0;
}