#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <functional>
#include "Node.h"

template <class T> class Array {
	public:
		void insert(T value);
		void purge(T value);
		T& search(T value);
		void forEach(std::function<void(T& value)>);
	private:
		std::vector<T> data;
		int binarySearch(T value);
};

#endif // ARRAY_H
