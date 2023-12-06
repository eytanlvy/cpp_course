#include "../includes/observable.hpp"

template <typename T>
void Observable<T>::notifyAll(const T& data) {
	for (Observer<T>* observer : observers) {
		observer->update(data);
	}
}

template <typename T>
void Observable<T>::addObserver(Observer<T>* observer) {
	observers.push_back(observer);
}

template <typename T>
void Observable<T>::removeObserver(Observer<T>* observer) {
	for (auto it = observers.begin(); it != observers.end(); ++it) {
		if (*it == observer) {
			observers.erase(it);
			return;
		}
	}
}

