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
	return (-1);
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

	if (idx == 0)
	{
		Cell *insert = new Cell(val);
		if (this->first != nullptr)
		{
			insert->connect(this->first);
			this->first = insert;
		} else {
			this->first = insert;
			this->last = insert;
		}
		return;
	}

	Cell *tmp {this->first};
	while (tmp != nullptr)
	{
		if (i == idx)
		{
			Cell *insert = new Cell(val);
			tmp->getPrev()->connect(insert);
			insert->connect(tmp);
			i = -1;
			break;
		}
		i++;
		tmp = tmp->getNext();
	}
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

void	fusionner(List &l, List &l1, List &l2)
{
	List *L = new List();
	Cell *tmp1 = l1.getFirst();
	Cell *tmp2 = l2.getFirst();
	int i = 0;
	while (tmp1 != nullptr && tmp2 != nullptr)
	{
		if (tmp1->getData() <= tmp2->getData())
		{
			L->insert(i, tmp1->getData());
			tmp1 = tmp1->getNext();

		} else {
			L->insert(i, tmp2->getData());
			tmp2 = tmp2->getNext();
		}
		i++;
	}

	while (tmp1 != nullptr)
    {
        L->insert(i, tmp1->getData());
        tmp1 = tmp1->getNext();
		i++;
    }

    while (tmp2 != nullptr)
    {
        L->insert(i, tmp2->getData());
        tmp2 = tmp2->getNext();
		i++;
    }
	l.setFirst(L->getFirst());
	l.setLast(L->getLast());
}


void	triFusion (List &l) {
	int length = l.length();
	if (length <= 1)
		return;
	List l1;
	List l2;

	int i = 0;
	while (i < length)
	{
		if (i < length /2)
			l1.insert(i, l.get(i));
		else
			l2.insert(i - (length / 2), l.get(i));
		i++;
	}
	triFusion(l1);
	triFusion(l2);

	fusionner(l, l1, l2);
};


ostream& operator<<( ostream &out , const List &x )
{
	if (x.getFirst() == nullptr)
	{
		out << "empty list" << endl;
		return out;
	}
	Cell *tmp = x.getFirst();
	while (tmp != nullptr)
	{
		out << tmp->getData() << " ";
		tmp = tmp->getNext();
	}
	out << endl;
	return out ;
}

int	main(void)
{
	List *l = new List();
	for (int i = 0; i < 12; i++)
	{
		l->insert(i, i * 50 % 12);
	}
	cout << "l = "<< *l << endl;
	l->insert(5, 1);
	cout << "l = "<< *l << endl;
	triFusion(*l);
	cout << "TRIFUSION" << endl;
	cout << "l = "<< *l << endl;
	return (0);
}
