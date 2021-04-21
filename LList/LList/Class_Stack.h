#pragma once
#include "Class_List.h"

class Class_Stack : public Class_List
{
public:
	Class_Stack();

	void Put(int n) override;
	int Get() override;
};

