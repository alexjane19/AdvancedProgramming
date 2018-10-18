#include "Planet.h"

Planet::Planet()
{
}
void Planet::createMoon()
{
	moon1 = new Moon[numofmoon];
}
void Planet::enterInfoMoon()
{
	for (int i = 0; i < numofmoon; i++)
	{
		std::cout << "Enter Name Moon's " << name << " : ";
		std::cin >> moon1[i].name;
		std::cout << "Enter distancePlanet's " << name << " : ";
		std::cin >> moon1[i].distancePlanet;
		std::cout << "Enter mass's " << name << " : ";
		std::cin >> moon1[i].mass;
		std::cout << "Enter Temperature's " << name << " : ";
		std::cin >> moon1[i].Temperature;
		std::cout << "Enter timeSpin's " << name << " : ";
		std::cin >> moon1[i].timeSpin;
	}
}

Planet::~Planet()
{
}

