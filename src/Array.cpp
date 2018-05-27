#include "../include/Array.h"


template <class T> Array<T>::Array() {

}

template <class T> Array<T>::~Array() {

}

template <class T> void Array<T>::insert(T value) {
	data.push_back(value);
}

template <class T> void Array<T>::purge(T value) {
	for (typename std::vector<T>::iterator i = data.begin(); i != data.end(); ++i) {
		if (value == *i) {
			data.erase(i);
			return;
		}
	}

}

template <class T> T& Array<T>::search(T value) {
	for (typename std::vector<T>::iterator i = data.begin(); i != data.end(); i++) {
		if (value == *i) {
			return *i;
		}
	}
	throw "notFound";
}

template <class T> void Array<T>::forEach(std::function<void(T& value)> callback) {
	for (typename std::vector<T>::iterator i = data.begin(); i != data.end(); i++) {
		callback(*i);
	}
}

template class Array<int>;
template class Array<Node<Array<int>>>;
