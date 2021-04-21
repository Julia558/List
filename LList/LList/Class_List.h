#pragma once
#include "Element.h"

class Class_List
{
public:
	Class_List();

	virtual void Put(int n) = 0 ;
	virtual int Get() = 0;

	//Указатель на начало списка 
	Element *Head;
	//Указатель на конец списка 
	Element *Tail;
	//Количество элементов
	int Count;
};

