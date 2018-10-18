#pragma once
#include<string>
#include"Star.h"
class Comet:public Star
{
private:
	int wieght;
	std::string place;
	int timeofturn;
public:
	Comet();
	~Comet();
};

