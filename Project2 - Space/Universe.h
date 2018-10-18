#pragma once
#include"Galaxy.h"
#include<string>
class Universe
{
private:
	int numofgalaxy;
	Galaxy *gay;
public:
	
	Universe(int);
	void createGalaxy();
	void enterInfoGalaxy();
	void show();
	~Universe();
};

