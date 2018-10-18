#pragma once
#include<string>
#include"Moon.h"
#include "LongNumber.h"
class Planet
{
	friend class Star;
	friend class  Galaxy;
	friend class System;
private:
	std::string name;
	LongNumber diagonal;
	LongNumber distnaceitsStar;
	double surfaceTemp;
	LongNumber rotatingStar;
	LongNumber fullRotation;
	LongNumber mass;
	int numofmoon;
public:
	Moon *moon1;
	Planet();
	LongNumber distancePlant();
	
	void createMoon();
	void enterInfoMoon();
	~Planet();
};

