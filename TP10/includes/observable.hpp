#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <iostream>
#include "observer.hpp"

class Observer;
template <typename T>
class Observable {
	private:
		std::vector<Observer<T>*> observers;

	protected:
		void notifyAll(const T& data);

	public:
		void addObserver(Observer<T>* observer);
		void removeObserver(Observer<T>* observer) ;
};

#endif
