//
// Created by mi on 01.12.2020.
//

#ifndef MYSPARSE_SPARSE_H
#define MYSPARSE_SPARSE_H

#include <iostream>
#include "Object.h"

template<typename T>
class Sparse
{
public:
	Object<T> *first = nullptr;
	Object<T> *last = nullptr;

public:
	Sparse() = default;

	~Sparse()
	{
		Object<T> *tmpPtr = last;
		Object<T> *tmpPtr2 = nullptr;
		while (tmpPtr)
		{
			tmpPtr2 = tmpPtr->prev;
			delete tmpPtr;
			tmpPtr = tmpPtr2;
		}
	}

	void addElement(const long &index, const T &data)
	{
		Object<T> *newObject = new Object<T>(index, data);
		if (!first)
			first = newObject;
		else if (!last)
		{
			last = newObject;
			last->prev = first;
			first->next = last;
		} else
		{
			newObject->prev = last;
			last->next = newObject;
			last = newObject;
		}
	}

	void removeElementByIndex(const long &index)
	{
		Object<T> *tmpPtr = first;
		while (tmpPtr && tmpPtr->index != index)
		{
			tmpPtr = tmpPtr->next;
		}
		if (!tmpPtr)
		{
			std::cout << "No such element found!" << std::endl;
		} else
		{
			Object<T> *tmpPtrPrev = tmpPtr->prev;
			tmpPtrPrev->next = tmpPtr->next;
			tmpPtr->prev = tmpPtrPrev;
			delete tmpPtr;
		}
	}

	void print()
	{
		Object<T> *tmpPtr = first;
		while (tmpPtr)
		{
			std::cout << tmpPtr->index << "\t" << tmpPtr->data << std::endl;
			tmpPtr = tmpPtr->next;
		}
	}

public:
	T &operator[](const long &i)
	{
		Object<T> *tmpPtr = first;
		while (tmpPtr && tmpPtr->index != i)
		{
			tmpPtr = tmpPtr->next;
		}
		if (!tmpPtr)
		{
			throw std::bad_exception();
		} else
		{
			return tmpPtr->data;
		}
	}
};


#endif //MYSPARSE_SPARSE_H
