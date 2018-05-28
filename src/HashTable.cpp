#include "HashTable.h"



template <class T> HashTable<T>::HashTable() {
	this->amount = 0;
	data.resize(5, -1);
}

template <class T> void HashTable<T>::insert(T value) {
	int index = this->hash(value);
	while (true) {
		if (this->data[index] == -1) {
			this->data[index] = value;
			break;
		}
		index++;
		if (index == this->data.size()) {
			index = 0;
		}
	}
	this->amount++;
	if (this->amount * 2 > (int)this->data.size()) {
		this->doubleSize();
	}
}

template <class T> void HashTable<T>::purge(T value) {
	int i = hash(value);
	while (true) {
		if (value == this->data[i]) {
			this->data[i] = -1;
			this->amount--;
			while (true) {
				i++;
				if (i == this->data.size()) {
					i = 0;
				} 
				else if (this->data[i] == -1) {
					return;
				}
				else {
					T temp = this->data[i];
					this->data[i] = -1;
					this->amount--;
					this->insert(temp);
				}
			}
		}
		else if (this->data[i] == -1) {
			return;
		}
		i++;
	}	
}

template <class T> T& HashTable<T>::search(T value) {
	int index = this->hash(value);
	while (true) {
		if (this->data[index] == value) {
			return this->data[index];
		} 
		else if (this->data[index] == -1) {
			throw "notFound";
		}
		else {
			index++;
		}

		if (index == this->data.size()) {
			index = 0;
		}
	}
}

template <class T> void HashTable<T>::forEach(std::function<void(T& value)> callback) {
	for (typename std::vector<T>::iterator i = data.begin(); i != data.end(); ++i) {
		if (*i != -1) {
			callback(*i);
		}
	}
}

template <class T> int HashTable<T>::hash(T value) {
	return value % data.size();
}

template <class T> void HashTable<T>::doubleSize() {
	std::vector<T> temporalArray;
	temporalArray = data;
	data = std::vector<T>(data.size() * 2, -1);
	for (typename std::vector<T>::iterator i = temporalArray.begin(); i != temporalArray.end(); ++i) {
		if (*i != -1) {
			this->insert(*i);
			this->amount--;
		}
	}
}

template class HashTable<int>;
template class HashTable<Node<HashTable<int>>>;
