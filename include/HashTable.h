#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <functional>
#include "Node.h"


template <class T> class HashTable  {
	public:
		HashTable();
		void insert(T value);
		void purge(T value);
		T& search(T value);
		void forEach(std::function<void(T& value)>);
	private:
		std::vector<T> data;
		void quickSort(std::vector<T>& arr);
		int hash(T value);
		void doubleSize();
		int amount;
};

#endif // HASHTABLE_H