#include "boxint.hpp"

int BoxInt::count = 0;

//Constructor
BoxInt::BoxInt(int d) : data{d}, last{std::time(nullptr)}
{
	cout << "Naissance d'une box "<< d << endl;
	count++;
}

//Destructor
BoxInt::~BoxInt()
{
	cout << "Mort d'une box "<< data << endl;
	count--;
}

void	BoxInt::set(int d)
{
	data = d;
}

int		BoxInt::get()
{
	last = std::time(nullptr);
	return data;
}

time_t	BoxInt::getLast() const {
    return last; // Getter pour l'heure de la dernière consultation
}

int		BoxInt::alive_count()
{
	return count;
}

ostream& operator<<( ostream &out , BoxInt &x )
{
	out << x.get() << endl;
	return out ;
}

void fonction1 ( BoxInt t ) { t . set (345) ; }
void fonction2 ( BoxInt * t ) { t -> set (678) ; }
void fonction3 ( BoxInt & t ) { t . set (1) ; }
//void fonction4 ( const BoxInt & t ) { t . set (13) ; }
//void fonction5 ( const BoxInt * t ) { t -> set (13) ; }
void fonction6 ( BoxInt * const t ) { t -> set (13) ; }
//void fonction7 ( BoxInt const * const t ) { t -> set (13) ; }
//void fonction8 ( const BoxInt & t ) { cout << t . get () << endl ; }

BoxInt * un_test ()
{
	BoxInt un_int {42};
	BoxInt un_autre_int { un_int };
	BoxInt * n = new BoxInt {54};
	cout << "nombre d'instances: "<< un_autre_int . alive_count() << endl;	
	return (n);
}

int		main()
{
	BoxInt* n = un_test();
	delete n;
	return EXIT_SUCCESS ;
}