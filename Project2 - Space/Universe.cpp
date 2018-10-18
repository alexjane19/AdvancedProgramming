#include "Universe.h"

using namespace std;

Universe::Universe(int num=0)
{
	numofgalaxy = num;
}

void Universe::createGalaxy()
{
		gay = new Galaxy[numofgalaxy];
}
void Universe::enterInfoGalaxy()
{
	for (int i = 0; i < numofgalaxy; i++)
	{
		std::cout << "Enter Name Galaxy: ";
		std::cin >> gay[i].name;
		std::cout << "Enter Number " << gay[i].name<<"s'System: ";
		std::cin >> gay[i].numofsystem;
		std::cout << "Enter " << gay[i].name <<"s'Center System : ";
		std::cin >> gay[i].centerSystem;
		gay[i].createSystem();
		gay[i].enterInforsystem();

	}
}
void Universe::show()
{
	for (int i = 0; i < numofgalaxy; i++)
	{
		cout << gay[i].name<<": "<<endl;
		cout << gay[i].centerSystem << endl;
		gay[i].show();

	}
}
Universe::~Universe()
{
}


