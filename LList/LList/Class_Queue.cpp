#include "Class_Queue.h"
#include "Element.h"
#include <iostream>
using namespace std;

Class_Queue::Class_Queue() : Class_List()
{ 
	Head = nullptr;
	Tail = nullptr;
	Count = 0;
}

void Class_Queue::Put(int n)
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

int Class_Queue::Get()
{
	//���� ������ �������
	if (Count == 0)
	{
		return -1;
	}

	int n = Head->data;

	Element *Temp = Head;

	//���� ����� ��������� � �������
	if (Head->next != nullptr)
	{
		Head->next->prev = nullptr;
		Head = Head->next;
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