#pragma once
#include<string>
#include"Planet.h"
#include "LongNumber.h"
class Star
{
	friend class System;
	friend class Galaxy;
private:
	std::string name;
	double surfaceTemp;
	LongNumber diagonal;
	int numofplanet;

public:
	Planet *pl;
	Star();
	Star(int);
	double aveTemperaturePlanetMoons(int);
	void createPlanet();
	~Star();
};

