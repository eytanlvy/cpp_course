#include "vector.hpp"

Vector::Vector(int *d, int s) : data{d}, size{s}
{
	cout << "Naissance d'un vecteur de taille "<< size << endl;
}

Vector::~Vector()
{
	cout << "Mort d'un vecteur de taille "<< size << endl;
}

int * Vector::get_data() const
{
	return data;
}

int Vector::get_size() const
{
	return size;
}

ostream&	operator<<( ostream &out , const Vector &x )
{
	out << "Vector of size " << x.get_size() << " containing: ";
	int* data {x.get_data()};
    for (int i = 0; i < x.get_size(); i++) {
        out << data[i] << " ";
    }
    
    out << endl;
    return out;
}

int	main(void)
{
	int *data = new int[5];
	for (int i = 0; i < 5; i++) {
		data[i] = i;
	}
	Vector v(data, 5);
	cout << v << endl;
	return (0);
}