#pragma once
#include<string>
#include "LongNumber.h"
class Moon
{
	friend class Planet;
	friend class Star;
	friend class System;
private:
	std::string name;
	LongNumber distancePlanet;
	double Temperature;
	LongNumber timeSpin;
	LongNumber mass;
public:
	Moon();
	~Moon();
};

