#pragma once
#include "Element.h"

class Class_List
{
public:
	Class_List();

	virtual void Put(int n) = 0 ;
	virtual int Get() = 0;

	//��������� �� ������ ������ 
	Element *Head;
	//��������� �� ����� ������ 
	Element *Tail;
	//���������� ���������
	int Count;
};

