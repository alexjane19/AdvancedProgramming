#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>

using namespace std;

class time1
{
private:
	int hour,
		minute,
		second;

public:
	void input(void)
	{
		cout << "hour: ";
		cin >> hour;
		cout << "minute: ";
		cin >> minute;
		cout << "second: ";
		cin >> second;
	}

	void print(void)
	{
		cout << hour << ":" << minute << ":" << second << setw(10);
	}

	int timeConvertToSec()
	{
		int timework;
		timework = (hour * 3600) + (minute * 60) + second;
		return timework;
	}

	~time1(){};
};

class employee
{
private:
	string name;
	time1 enter;
	time1 exit;
	time1 extraWork;
	int enterPerSec;
	int exitPerSec;
	int exworkPerSec;
	double fixedSalary;
	double extraSalary;
	double totalReceived;
	const int baseTimework = 28800;//=8 hours
	const double baseSalaryPerSec = 277.77;//Per second to 277.77 Rials for work
	const int exSalaryPerSec = 300;//Per second to 300 Rials for extrawork
public:
	void getinfo()
	{
		cout << "Name of empolyee: ";
		cin >> name;
		cout << "Time of arrival: \n";
		enter.input();
		enterPerSec = enter.timeConvertToSec();
		cout << "Departure time: \n";
		exit.input();
		exitPerSec = exit.timeConvertToSec();
		cout << "Time Overtime: \n";
		extraWork.input();
		exworkPerSec = extraWork.timeConvertToSec();
	}

	void calculateSalary()
	{
		fixedSalary = (exitPerSec - enterPerSec)*baseSalaryPerSec;
		totalReceived = fixedSalary;
		int tempTime = baseTimework - (exitPerSec - enterPerSec);

		if (tempTime == 0)
			extraSalary = exworkPerSec*exSalaryPerSec;
		else
		{
			if (tempTime<exworkPerSec)
				fixedSalary = tempTime*baseSalaryPerSec;

			if (tempTime>exworkPerSec)
				fixedSalary = exworkPerSec*baseSalaryPerSec;

			if ((exworkPerSec - tempTime) > 0)
				extraSalary = (exworkPerSec - tempTime)*exSalaryPerSec;
		}
		fixedSalary += totalReceived;
		totalReceived = fixedSalary + extraSalary;
	}

	void print()
	{
		cout << "Name of empolyee: ";
		cout << name << endl;
		cout << "Arrival" << setw(15) << "Departure" << setw(15) << "Overtime" << endl;
		enter.print();
		exit.print();
		extraWork.print();
		cout << endl;
		cout << "FixedSalary" << setw(15) << "ExtraSalary" << setw(17) << "TotalReceived" << endl;
		cout << fixed << setprecision(2) << fixedSalary << setw(15) << extraSalary << setw(16) << totalReceived;
		cout << endl;
	}

	~employee(){}
};

int main()
{
	const int num = 30;
	employee person[num];

	for (int i = 0; i < num; i++)
	{
		person[i].getinfo();
		person[i].calculateSalary();
	}

	system("cls");

	for (int i = 0; i < num; i++)
	{
		person[i].print();
		cout << endl;
	}
		
	system("pause");
	return 0;
}
