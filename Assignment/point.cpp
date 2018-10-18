#include<iostream>
#include<cstdlib>
using namespace std;

struct Point
{
	int x
		,y
		,dx
		,dy;

	void input()
	{
		cout << "X: ";
		cin >> x;
		cout << "Y: ";
		cin >> y;
	}
	
	void print()
	{
		cout << "("<<x<<","<<y<<")\n";
	}

	void move()
	{
		cout << "x+dx--> dx=";
		cin >> dx;
		x += dx;
		cout << "y+dy--> dy=";
		cin >> dy;
		y += dy;
	}
};

int main()
{
	Point p;
	p.input();
	p.print();
	p.move();
	p.print();

	system("pause");
	return 0;
}
