#pragma once
#include<string>
#include "Star.h"
class System
{
	friend class Galaxy;
private:
	std::string name;
public:
	Star star1;
	System();
	double AveTempSystem();
	LongNumber TotalWeightSystem();
	~System();
};

