#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>

class SimpleVector
{
public:
	SimpleVector() : currentSize(0), currentCapacity(10)
	{
		data = new T[currentCapacity];
	}
	SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity)
	{
		data = new T[currentCapacity];
	}
	SimpleVector(const SimpleVector& other) : currentSize(other.currentSize), currentCapacity(other.currentCapacity)
	{
		data = new T[currentCapacity];
		for (int i = 0; i < currentSize; ++i)
		{
			data[i] = other.data[i];
		}
	}

	~SimpleVector()
	{
		delete[] data;
	}

	void push_back(const T& value)
	{
		if (currentSize >= currentCapacity)
		{
			resize(currentCapacity + 5);
		}
		data[currentSize++] = value;
	}

	void resize(int newcapacity)
	{
		if (newcapacity <= currentCapacity) return;
		T* newData = new T[newcapacity];
		for (int i = 0; i < currentSize; ++i)
		{
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		currentCapacity = newcapacity;

	}

	void pop_back()
	{
		if (currentSize > 0)
		{
			--currentSize;
		}
	}

	int size()
	{
		return currentSize;
	}
	
	int capacity()
	{
		cout << "현재 백터의 총량 크기 : " << currentCapacity << endl;
		return currentCapacity;
	}

	void sortData()
	{
		sort(data, data + currentSize);
	}

	void pl()
	{
		for (int i = 0; i < currentSize; ++i)
		{
			cout << data[i] << " .";
		}
		cout << endl;
	}

private:
	T* data;
	int currentSize;
	int currentCapacity;
};

int main()
{
	SimpleVector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	cout << "백터의 크기 : " << vec.size() << endl;
	vec.pop_back();
	cout << "팝 백 함수 작동후 백터의 크기 : " << vec.size() << endl; 
	vec.capacity();
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(9);
	vec.push_back(100);
	vec.push_back(11);
	vec.push_back(12);
	cout << "푸쉬 백 함수 작동후 백터의 크기 : " << vec.size() << endl; 
	vec.capacity();
	cout << "정렬전 백터 내부 데이터 : ";
	vec.pl();
	vec.sortData();
	cout << "정렬된 백터 내부 데이터 : ";
	vec.pl();

	return 0;
}
