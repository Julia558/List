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

int Class_Stack::Get()
{
	//Если пустщй стек
	if (Count == 0)
	{
		return -1;
	}

	int n = Tail->data;

	Element *Temp = Tail;

	//Если много элементов в очереди
	if (Tail->prev != nullptr)
	{
		Tail->prev->next = nullptr;
		Tail = Tail->prev;
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