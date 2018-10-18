#include<iostream>
#include<cstdlib>
using namespace std;

struct student
{
	char fname[50];
	char lname[50];
	char id[10];
	float ave;

	void input()
	{
		cout << "ID: ";
		cin >> id;
		cout << "First Name: ";
		cin >> fname;
		cout << "Last Name: ";
		cin >> lname;
		cout << "Average: ";
		cin >> ave;
	}

	void print()
	{
		cout << "ID: "<<id<<endl;
		cout << "First Name: " << fname << endl;
		cout << "Last Name: " << lname << endl;
		cout << "Average: " << ave << endl;
	}
	
};

int main()
{
	student stu;
	stu.input();
	stu.print();

	system("pause");
	return 0;
}
