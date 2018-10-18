#include "Star.h"


Star::Star(int num=0)
{
	numofplanet = num;
}

void Star::createPlanet()
{
	pl = new Planet[numofplanet];
}

double Star::aveTemperaturePlanetMoons(int z)
{
	double ave = pl[z].surfaceTemp;
	for (int i = 0; i < pl[z].numofmoon; i++)
	{
		ave += pl[z].moon1[i].Temperature;
	}
	ave /= pl[z].numofmoon + 1;
	return ave;
}
Star::~Star()
{
}
