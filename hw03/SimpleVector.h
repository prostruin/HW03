#ifndef SIMPLE_VECTOR_H_
#define SIMPLE_VECTOR_H_

template<typename T>
class SimpleVector
{
public:
	SimpleVector();
	SimpleVector(int capacity);
	~SimpleVector();
	void push_back(const T& value);
	void pop_back();
	int size();
	int capacity();

private:
	T* data;
	int currentSize;
	int currentCapacity;
};


#endif