#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <iostream>


template <typename T>
class Observer {
	public:
		virtual void update(const T& data) = 0;
};

#endif