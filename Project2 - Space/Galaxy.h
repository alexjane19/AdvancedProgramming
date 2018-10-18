#pragma once
#include<string>
#include "Point.h"
#include"Universe.h"
#include"System.h"
class Galaxy
{
	friend class Universe;
private:
	std::string name;
	int numofsystem;
	std::string centerSystem;
public:
	System *sys;
	Galaxy();
	Galaxy(int);
	void createSystem();
	void enterInforsystem();
	LongNumber distance(Point p);
	LongNumber TotalWeightGalaxy();
	void show();
	~Galaxy();
};

