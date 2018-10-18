#include "Universe.h"
using namespace std;

Galaxy::Galaxy(int num=0)
{
	numofsystem = num;
}

void Galaxy::createSystem() 
{
	sys = new System[numofsystem];
}
void Galaxy::enterInforsystem()
{
	for (int i = 0; i < numofsystem; i++)
	{
		std::cout << "Enter Name "<<name<<"'s System: ";
		std::cin>>sys[i].name;
		std::cout << "Enter Name " << sys[i].name<<"'s Star: ";
		std::cin >> sys[i].star1.name;
		std::cout << "Enter Diagonal " << sys[i].star1.name <<" : ";
		std::cin >> sys[i].star1.diagonal;
		std::cout << "Enter SurfaceTemp " << sys[i].star1.name << " : ";
		std::cin >> sys[i].star1.surfaceTemp;
		std::cout << "Enter Number Planet " << sys[i].star1.name << " : ";
		std::cin >> sys[i].star1.numofplanet;
		sys[i].star1.createPlanet();
		for (int j = 0; j < sys[i].star1.numofplanet; j++)
		{
			std::cout << "Enter Name Planet " << sys[i].star1.name << " : ";
			std::cin >> sys[i].star1.pl[j].name;
			std::cout << "Enter Diagonal's " << sys[i].star1.pl[j].name<< " : ";
			std::cin >> sys[i].star1.pl[j].diagonal;
			std::cout << "Enter distnaceitsStar's " << sys[i].star1.pl[j].name << " : ";
			std::cin >> sys[i].star1.pl[j].distnaceitsStar;
			std::cout << "Enter fullRotation's " << sys[i].star1.pl[j].name << " : ";
			std::cin >> sys[i].star1.pl[j].fullRotation;
			std::cout << "Enter mass's " << sys[i].star1.pl[j].name << " : ";
			std::cin >> sys[i].star1.pl[j].mass;
			std::cout << "Enter surfaceTemp's " << sys[i].star1.pl[j].name << " : ";
			std::cin >> sys[i].star1.pl[j].surfaceTemp;
			std::cout << "Enter rotatingStar's " << sys[i].star1.pl[j].name << " : ";
			std::cin >> sys[i].star1.pl[j].rotatingStar;
			std::cout << "Enter Number Moon's " << sys[i].star1.pl[j].name << " : ";
			std::cin >> sys[i].star1.pl[j].numofmoon;
			std::cout << "Enter Diagonal's " << sys[i].star1.pl[j].name << " : ";
			sys[i].star1.pl[j].createMoon();
			sys[i].star1.pl[j].enterInfoMoon();
		}
		
	}
}
LongNumber Galaxy::TotalWeightGalaxy()
{
	LongNumber sum("0");
	for (int i = 0; i < numofsystem; i++)
	{
		sum = sum + sys[i].TotalWeightSystem();
	}
	return sum;
}
void Galaxy::show()
{
	for (int j = 0; j < numofsystem; j++)
	{
		cout << sys[j].name << ": " << endl;
		cout << sys[j].star1.name << endl;
		cout << sys[j].star1.diagonal << endl;
		cout << sys[j].star1.surfaceTemp << endl;
		for (int k = 0; k < sys[j].star1.numofplanet; k++)
		{
			cout << sys[j].star1.pl[k].name << endl;
			cout << sys[j].star1.pl[k].diagonal << endl;
			cout << sys[j].star1.pl[k].distnaceitsStar << endl;
			cout << sys[j].star1.pl[k].fullRotation << endl;
			cout << sys[j].star1.pl[k].mass << endl;
			cout << sys[j].star1.pl[k].rotatingStar<<endl;
			cout << sys[j].star1.pl[k].surfaceTemp<<endl;

		}
	}
}
Galaxy::~Galaxy()
{
}
