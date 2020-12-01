//
// Created by mi on 01.12.2020.
//

#ifndef MYSPARSE_OBJECT_H
#define MYSPARSE_OBJECT_H

#include "ObjectData.h"

template<typename T>
class Object : public ObjectData<T>
{
public:
	Object<T> *prev;
	Object<T> *next;

public:
	Object(const long &index, const T &data, Object *prev = nullptr, Object *next = nullptr) : ObjectData<T>(index, data)
	{
		this->next = next;
		this->prev = prev;
	}

	void setNext(Object *newNext)
	{
		next = newNext;
	}

	void setPrev(Object *newPrev)
	{
		prev = newPrev;
	}
};


#endif //MYSPARSE_OBJECT_H
