#include "System.h"


System::System()
{
}
double System::AveTempSystem()
{
	double ave = 0;//star1.surfaceTemp;
	for (int i = 0; i < star1.numofplanet; i++)
	{
		ave+=star1.aveTemperaturePlanetMoons(i);
	}
	ave += star1.surfaceTemp;
	ave /= star1.numofplanet + 1;
	return ave;
}
LongNumber System::TotalWeightSystem()
{
	LongNumber sum("0");
	for (int i = 0; i < star1.numofplanet; i++)
	{
		for (int j = 0; j < star1.pl[i].numofmoon;j++)
			sum = sum + star1.pl[i].moon1[j].mass;
		sum = sum  + star1.pl[i].mass;
	}
	return sum;
}
System::~System()
{
}
