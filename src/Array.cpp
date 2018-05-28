#include "Array.h"

template <class T> void Array<T>::insert(T value) {
	typename std::vector<T>::iterator i;
	for (i = data.begin(); i != data.end(); i++) {
		if (*i > value) {
			break;
		}
	}
	data.insert(i, value);
}

template <class T> void Array<T>::purge(T value) {
	
	int indexOfValue = binarySearch(value);
	if (indexOfValue != -1) {
		data.erase(data.begin() + indexOfValue);
	}
	
}

template <class T> T& Array<T>::search(T value) {
	int indexOfValue = binarySearch(value);
	if (indexOfValue == -1) {
		throw "notFound";
	}
	return data[indexOfValue];
}

template <class T> void Array<T>::forEach(std::function<void(T& value)> callback) {
	for (typename std::vector<T>::iterator i = data.begin(); i != data.end(); i++) {
		callback(*i);
	}
}

template <class T> int Array<T>::binarySearch(T value) {
	int leftLimit = 0;
	int rightLimit = this->data.size() - 1;
	int middle;

	while (leftLimit <= rightLimit) {
		middle = (leftLimit + rightLimit) / 2;
		if (value == data[middle]) {
			return middle;
		}
		else if (value < data[middle]) {
			rightLimit = middle - 1;
		}
		else {
			leftLimit = middle + 1;
		}
	}
	return -1;
}

template class Array<int>;
template class Array<Node<Array<int>>>;
