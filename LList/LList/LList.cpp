// LList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Class_List.h"
#include "Class_Queue.h"
#include "Class_Stack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Class_Queue QueOb;
	Class_Stack StOb;

	int input;
	char symbol;

	do
	{
		cout << "Куда поместить значение? в очередь или стек? (О/С) : ";
		cin >> symbol;
		symbol = tolower(symbol);
		if (symbol == 'o')
		{
			cout << "\nВведите данные в очередь. По окончании ввода введите 0:\n"; \
				while (true)
				{
					cin >> input;
					if (input == 0)
						break;
					QueOb.Put(input);
				}
		}
		else if (symbol == 'c')
		{
			cout << "\nВведите данные в стек. По окончании ввода введите 0:\n";
			while (true)
			{
				cin >> input;
				if (input == 0)
					break;
				StOb.Put(input);
			}
		}
		else
			continue;

		cout << "Откуда извлечь значение?(О/С) : ";
		cin >> symbol;
		symbol = tolower(symbol);

		if (symbol == 'o')
		{
			cout << "Очередь: ";
			if (QueOb.Count == 0)
			{
				cout << "Очередь пустая, невозможно получить элементы!";
			}
			while (QueOb.Count > 0)
			{
				int tmp = QueOb.Get();
				if (tmp != -1)
					cout << tmp << " ";
			}
			cout << endl << "----------------------------------";
			cout << endl << endl;
		}
		else if (symbol = 'c')
		{
			cout << "Стек: ";
			if (StOb.Count == 0)
			{
				cout << "Стек пуст, невозможно получить элементы!";
			}
			while (StOb.Count > 0)
			{
				int tmp = StOb.Get();
				if (tmp != -1)
					cout << tmp << " ";
			}
			cout << endl << "----------------------------------";
			cout << endl << endl;
		}
		else
			continue;
	} while (symbol != '0');
	system("pause");
}