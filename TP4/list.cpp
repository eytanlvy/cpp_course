#include "list.hpp"

List::List () : first{nullptr}, last{nullptr}
{
	cout << "Liste créée: " << *this << endl;
}

List::~List()
{
	cout << "Liste détruite: " << *this << endl;

	if (this->first != nullptr)
	{
		Cell *tmp = this->first;
		while (tmp != nullptr)
		{
			Cell *tmp2 = tmp->getNext();
			delete tmp;
			tmp = tmp2;
		}
	}
}

int List::length() const
{
	int i = 0;
	Cell *tmp = this->first;
	while (tmp != nullptr)
	{
		i++;
		tmp = tmp->getNext();
	}
	return i;
}

int List::get(int idx)
{
	int i = 0;
	Cell *tmp = this->first;
	while (tmp != nullptr)
	{
		if (i == idx)
			return tmp->getData();
		i++;
		tmp = tmp->getNext();
	}
}

int List::find(int val)
{
	int i = 0;
	Cell *tmp {this->first};
	while (tmp != nullptr)
	{
		if (tmp->getData() == val)
			return (i);
		i++;
		tmp = tmp->getNext();
	}
	return (-1);
}

void List::set(int idx, int val)
{
	int i = 0;
	Cell *tmp {this->first};
	while (tmp != nullptr)
	{
		if (i == idx)
			tmp->setData(val);
		i++;
		tmp = tmp->getNext();
	}
}

void List::insert(int idx, int val)
{
	int i = 0;
	Cell *tmp {this->first};
	while (tmp != nullptr)
	{
		if (i == idx)
		{
			Cell *insert = new Cell(val);
			tmp->getPrev()->connect(insert);
			insert->getNext()->connect(tmp);
			i = -1;
			break;
		}
		i++;
		tmp = tmp->getNext();
	}
	delete tmp;
	if (i == idx)
	{
		Cell *insert = new Cell(val);
		this->getLast()->connect(insert);
		this->last = insert;
	}
}

void List::del(int idx)
{
	int i = 0;
	Cell *tmp {this->first};
	while (tmp != nullptr)
	{
		if (i == idx)
		{
			if (tmp->getPrev() != nullptr)
				tmp->getPrev()->connect(tmp->getNext());
			else
				this->first = tmp->getNext();
			if (tmp->getNext() != nullptr)
				tmp->getPrev()->connect(tmp->getNext());
			else
				this->last = tmp->getPrev();
			delete tmp;
		}
		i++;
		tmp = tmp->getNext();
	}
}

void bubbleSort(List &l)
{
	int i;
	int j;
	int length;

	length = l.length();
	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (l.get(i) > l.get(j))
			{
				int tmp = l.get(i);
				l.set(i, l.get(j));
				l.set(j, tmp);
			}
		}
	}
}

void triFusion (List &l) {}; //TODO

ostream& operator<<( ostream &out , const List &x )
{
	out << x.getFirst() << " ---> " << x.getLast() << endl ;
	return out ;
}
