#include "Array.h"

template <class T> void Array<T>::insert(T value) { //Inserting the value in the Array
	typename std::vector<T>::iterator i;
	for (i = data.begin(); i != data.end(); i++) {
		if (*i > value) {
			break;
		}
	}
	data.insert(i, value);
}

template <class T> void Array<T>::purge(T value) { //Deleting the value in the Array

	int indexOfValue = binarySearch(value); //Searching for the  value we wish to delete through binary search method
	if (indexOfValue != -1) {
		data.erase(data.begin() + indexOfValue);
	}

}

template <class T> T& Array<T>::search(T value) { //Searching for a value using binary search method
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

template <class T> int Array<T>::binarySearch(T value) { //Binary Search Method that we use to find value
	int leftLimit = 0; //Defining the left limit as the first cell of the array
	int rightLimit = this->data.size() - 1; //Defining the right limit as the last cell of the array
	int middle;

	while (leftLimit <= rightLimit) {
		middle = (leftLimit + rightLimit) / 2; //Defining the middle cell of the array as the sum of the left and right limit divided by 2
		if (value == data[middle]) {
			return middle;  //If the value is in the middle of the array,we return its position
		}
		else if (value < data[middle]) { //If it's less than the middle of the array,we change the right limit and do the same procedure in the first half of the array
			rightLimit = middle - 1;
		}
		else { //If it's larger than the middle of the array,we change the left limit and do the same procedure in the second half of the array
			leftLimit = middle + 1;
		}
	}
	return -1;
}

template class Array<int>;
template class Array<Node<Array<int>>>;
