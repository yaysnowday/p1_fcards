#ifndef UNIQUE_VECTOR_H
#define UNIQUE_VECTOR_H

template <class T>
class UniqueVector {
public:
	UniqueVector();
	~UniqueVector();
	unsigned int capacity();
	unsigned int size();
	bool empty();
	bool contains(const T& data);
	bool at(unsigned int pos, T& data);
	bool insert(const T& data);
	bool insert(const T& data, unsigned int pos);
	bool push_front(const T& data);
	bool remove(const T& data);
	bool remove(unsigned int pos, T& data);
	bool pop_back(T& data);
	void clear();
	//void getElement(int pos);
	bool operator==(const UniqueVector<T>& other);

private:
	T *dArr;
	T *tmpArr;
	//T data;
	unsigned int numElements;
	unsigned int maxNumElements;
	unsigned int initNumElements = 3;
	void doubleArray();
};

#include "UniqueVector.cpp"
#endif