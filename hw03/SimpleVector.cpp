#include "SimpleVector.h"
#include <iostream>
using namespace std;




template<typename T>
SimpleVector<T>::SimpleVector() : currentSize(0), currentCapacity(10)
{
	data = new T[currentCapacity];
}

template<typename T>
SimpleVector<T>::SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity)
{
	data = new T[currentCapacity];
}

template<typename T>
SimpleVector<T>::~SimpleVector()
{
	delete[] data;
}

template<typename T>
void SimpleVector<T>:: push_back(const T& value)
{
	if (currentSize < currentCapacity)
	{
		data[currentSize++] = value;
	}
}

template<typename T>
void SimpleVector<T>::pop_back()
{
	if (currentSize > 0)
	{
		--currentSize;
	}

}

template<typename T>
int SimpleVector<T>::size()
{
	return currentSize;
}

template<typename T>
int SimpleVector<T>::capacity()
{
	return currentCapacity;
}







