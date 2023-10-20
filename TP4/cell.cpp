#include "cell.hpp"

Cell::Cell (int d, Cell *n, Cell *p) : data{d}, next{n}, prev{p}
{
	cout << "Cellule créée: " << *this << endl;
}

Cell::Cell (int d) : data{d}, next{nullptr}, prev{nullptr}
{
	cout << "Cellule créée: " << *this << endl;
}

void	Cell::connect (Cell *new_next)
{
	cout << "in connect" << endl;
	new_next->prev = this;
	cout << "Cellule connectée: " << *this << " -> " << *new_next << endl;
	this->next = new_next;
}

void	Cell::disconnectNext()
{
	if (this->next != nullptr)
	{
		this->next->prev = nullptr;
		this->next = nullptr;
	}
}

void	Cell::disconnectPrev()
{
	if (this->prev != nullptr)
	{
		this->prev->next = nullptr;
		this->prev = nullptr;
	}
}

Cell::~Cell()
{
	cout << "Cellule détruite: " << *this << endl;
}

ostream& operator<<(ostream &out, const Cell &x) {
	out << x.getData();
    return out;
}