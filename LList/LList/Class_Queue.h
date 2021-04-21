#pragma once
#include <iostream>
#include "Class_List.h"

class Class_Queue : public Class_List
{
public:
	Class_Queue();

	void Put(int n) override;
	int Get() override;
};