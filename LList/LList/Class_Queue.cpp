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
	//Создаем новый элемент очереди 
	Element *Item = new Element();

	//Устанавливаем хранимое значение 
	Item->data = n;
	
	//Добавляем в конец очереди
	//если очередь пустая, то присваиваем значение первому элементу
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
	//Если пустая очередь
	if (Count == 0)
	{
		return -1;
	}

	int n = Head->data;

	Element *Temp = Head;

	//Если много элементов в очереди
	if (Head->next != nullptr)
	{
		Head->next->prev = nullptr;
		Head = Head->next;
		delete Temp;
	}
	//Если один элемент в очереди
	else
	{
		delete Temp;
		Head = nullptr;
		Tail = nullptr;
	}
	Count--;

	return n;
}