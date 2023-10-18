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
	delete tmp;
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
	delete tmp;
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
	delete tmp;
}

void List::insert(int idx, int val)
{
	int i = 0;
	Cell *tmp {this->first};

	if (idx == 0)
	{
		Cell *insert = new Cell(val);
		insert->connect(this->first);
		this->first = insert;
		return;
	}
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
	delete tmp;
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
	Cell *tmp1 = l1.getFirst();
	Cell *tmp2 = l2.getFirst();
	int i = 0;
	while (tmp1 != nullptr && tmp2 != nullptr)
	{
		if (tmp1->getData() <= tmp2->getData())
		{
			l.insert(i, tmp1->getData());
			tmp1 = tmp1->getNext();

		} else {
			l.insert(i, tmp2->getData());
			tmp2 = tmp2->getNext();
		}
		i++;
	}
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
		if (i < length /2){
			cout << "APAGNAN" << endl;
			l1.insert(i, l.get(i));
			cout << "APAGNAN2222" << endl;
		}
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
	Cell *c1 = new Cell(10);
	Cell *c2 = new Cell(2);
	Cell *c3 = new Cell(3);
	Cell *c4 = new Cell(8);
	Cell *c5 = new Cell(5);
	Cell *c6 = new Cell(2);
	Cell *c7 = new Cell(7);
	Cell *c8 = new Cell(8);
	Cell *c9 = new Cell(9);
	List *l = new List();
	l->setFirst(c1);
	l->setLast(c9);
	c1->connect(c2);
	c2->connect(c3);
	c3->connect(c4);
	c4->connect(c5);
	c5->connect(c6);
	c6->connect(c7);
	c7->connect(c8);
	c8->connect(c9);
	cout << "l = "<< *l << endl;
	l->insert(5, 1);
	cout << "l = "<< *l << endl;
	return (0);
}
