#include "Class_Stack.h"
#include "Element.h"
#include <iostream>
using namespace std;

Class_Stack::Class_Stack() : Class_List()
{
	Head = nullptr;
	Tail = nullptr;
	Count = 0;
}

void Class_Stack::Put(int n)
{
	//������� ����� ������� ������� 
	Element *Item = new Element();

	//������������� �������� �������� 
	Item->data = n;

	//��������� � ����� �������
	//���� ������� ������, �� ����������� �������� ������� ��������
	if (Count == 0)
	{
		Tail = Item;
		Head = Item;
	}
	else
	{
		Tail->next = Item;
		Item->prev = Tail;
		Tail = Item;
	}
	Count++;
}

int Class_Stack::Get()
{
	//���� ������ ����
	if (Count == 0)
	{
		return -1;
	}

	int n = Tail->data;

	Element *Temp = Tail;

	//���� ����� ��������� � �������
	if (Tail->prev != nullptr)
	{
		Tail->prev->next = nullptr;
		Tail = Tail->prev;
		delete Temp;
	}
	//���� ���� ������� � �������
	else
	{
		delete Temp;
		Head = nullptr;
		Tail = nullptr;
	}
	Count--;

	return n;
}