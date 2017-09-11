#pragma once
#include<iostream>
using namespace std;


// Amortized Time Analysis
template<typename T>
class MyVector
{
private:
	T *data;
	int capacity;
	int size;
	void resize(int newCapacity);
public:
	MyVector()
	{
		data = new T[10];
		capacity = 10;
		size = 0;

	}
	~MyVector()
	{
		delete[] data;
	}
	//O(n)
	void resize(int newCapacity)
	{
		assert(newCapacity >= size);
		T *newData = new T[newCapacity];
		for (int i = 0; i < size; i++)
		{
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		capacity = newCapacity;
	}
	//push_back O(1)
	//1 1 1 1 1 1  1 n

	void push_back(T e)
	{
		if (size == capacity)
			resize(2 * capacity);
		assert(size < capacity);
		data[size++] = e;
	}
	T pop_back()
	{
		assert(size > 0);
		return data[--size];
	}

};