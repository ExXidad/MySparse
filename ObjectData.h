//
// Created by mi on 01.12.2020.
//

#ifndef MYSPARSE_OBJECTDATA_H
#define MYSPARSE_OBJECTDATA_H


template<typename T>
class ObjectData
{
public:
	long index;
	T data;

public:
	ObjectData(const long &index, const T &data)
	{
		this->index = index;
		this->data = data;
	}
};


#endif //MYSPARSE_OBJECTDATA_H
