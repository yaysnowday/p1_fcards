#ifndef UNIQUE_VECTOR_CPP
#define UNIQUE_VECTOR_CPP

#include "UniqueVector.h"
#include <iostream>

using namespace std;

template <class T>
UniqueVector<T>::UniqueVector() {
	dArr = new T[initNumElements];
	maxNumElements = initNumElements;
	numElements = 0;
}

template <class T>
UniqueVector<T>::~UniqueVector() {
	delete[] dArr;
	delete[] tmpArr;
	maxNumElements = 0;
	numElements = 0;
}

template <class T>
unsigned int UniqueVector<T>::capacity() {
	return maxNumElements;
}

template <class T>
unsigned int UniqueVector<T>::size() {
	return numElements;
}

template <class T>
bool UniqueVector<T>::empty() {
	bool isEmpty;

	if (numElements == 0) {
		isEmpty = true;
	}
	else {
		isEmpty = false;
	}

	return isEmpty;
}

template <class T>
bool UniqueVector<T>::contains(const T& data) {
	bool isFound = false;

	if (!empty()) {
		for (unsigned int i = 0; i<numElements; ++i) {
			if (dArr[i] == data) {
				isFound = true;
			}
		}
	}

	return isFound;
}

template <class T>
bool UniqueVector<T>::at(unsigned int pos, T& data) {
	bool isAt = false;

	if (pos < numElements) {
		data = dArr[pos];
		isAt = true;
	}

	return isAt;
}

template <class T>
bool UniqueVector<T>::insert(const T& data) {
	bool isInserted = false;

	if (!contains(data)) {
		if (numElements >= maxNumElements) {
			doubleArray();
		}

		dArr[numElements] = data;
		++numElements;
		isInserted = true;
	}

	return isInserted;
}

template <class T>
bool UniqueVector<T>::insert(const T& data, unsigned int pos) {
	bool isInserted = false;

	if (!contains(data)) {
		if (numElements >= maxNumElements) {
			doubleArray();
		}

		T tmp1 = dArr[pos];
		T tmp2;
		for (int i = pos; i < numElements; ++i) {
			tmp2 = dArr[i + 1];
			dArr[i + 1] = tmp1;
			tmp1 = tmp2;
		}

		dArr[pos] = data;
		++numElements;
		isInserted = true;
	}

	return isInserted;
}

template <class T>
bool UniqueVector<T>::push_front(const T& data) {
	return insert(data, 0);
}

template <class T>
bool UniqueVector<T>::remove(const T& data) {
	bool isRemoved = false;

	if (empty()) {
		return isRemoved;
	}

	if (contains(data)) {
		for (unsigned int i = 0; i < numElements; ++i) {
			if (dArr[i] == data) {
				unsigned int j = i;
				int dataPos = j;

				for (j = dataPos; j < numElements; ++j) {
					dArr[j] = dArr[j + 1];
				}

				--numElements;
				return true;
			}
		}
	}

	return isRemoved;
}

template <class T>
bool UniqueVector<T>::remove(unsigned int pos, T& data) {
	bool isRemoved = false;

	if (at(pos, data)) {
		for (int i = pos; i < numElements; ++i) {
			dArr[i] = dArr[i + 1];
		}

		--numElements;
		isRemoved = true;
	}

	return isRemoved;
}

template <class T>
bool UniqueVector<T>::pop_back(T& data) {
	bool isPopped = false;
	int lastElement = numElements - 1;

	if (!empty()) {
		isPopped = at(lastElement, data);
		--numElements;
	}

	return isPopped;
}

template <class T>
void UniqueVector<T>::clear() {
	delete[] dArr;
	dArr = new T[initNumElements];
	maxNumElements = 3;
	numElements = 0;
}

template <class T>
bool UniqueVector<T>::operator==(const UniqueVector<T>& other) {
	if (numElements == other.size()) {
		for (unsigned int i = 0; i<numElements; ++i) {
			if (other[i] != dArr[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

template <class T>
void UniqueVector<T>::doubleArray() {
	tmpArr = new T[maxNumElements * 2];
	for (unsigned int i = 0; i<numElements; ++i) {
		tmpArr[i] = dArr[i];
	}

	maxNumElements *= 2;

	dArr = tmpArr;
	//delete[] tmpArr;
}

//template <class T>
//void UniqueVector<T>::getElement(int pos) {
//	cout << "[" << pos << "]: " << dArr[pos] << endl;
//}

#endif