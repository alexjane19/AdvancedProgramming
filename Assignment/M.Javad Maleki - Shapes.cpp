#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Point
{
private:
	double x, y;
public:
	friend ostream & operator<<(ostream & o1, Point p);
	Point(double a = 0, double b = 0) :x(a), y(b){}
	void setX(double x)
	{
		this->x = x;
	}
	double getX()
	{
		return x;
	}
	void setY(double y)
	{
		this->y = y;
	}
	double getY()
	{
		return y;
	}

	double distance(Point p)
	{
		return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
	}

	Point &operator=(Point pt)
	{
		this->x=pt.x;
		this->y=pt.y;
		return *this;
	}

	friend class Shape;
};
class Shape
{
private:
	string name;
	string color;
protected:
	int sides;
	Point *positoin;
public:
	
	Shape()
	{
		name = "UnknownName";
		color = "White";
		positoin = 0;
		sides = 0;
	}
	Shape(string name, string color) :name(name), color(color)
	{ 
		positoin = 0;
		sides = 0;
	}
	Shape(string name, string color, Point *positoin = 0, int side = 0) :name(name), color(color), sides(side)
	{
		if(positoin)
		{
			this->positoin=new Point[side];
			memcpy(this->positoin,positoin,sizeof(Point)*side);
		}
	}

	Shape(Shape &kindofshape)
	{
		name = kindofshape.name;
		color = kindofshape.color;
		sides = kindofshape.sides;
		if(sides>0 && kindofshape.positoin) positoin = new Point[sides];
		for (int i = 0; i < sides; i++)
			positoin[i] = kindofshape.positoin[i];
	}

	~Shape()
	{
		name = "";
		color = "";
		sides = 0;
		if (positoin) delete[] positoin;
		positoin = 0;
		cout << "\ndestroy";
	}
	void setName(string name)
	{
		this->name = name;
	}
	string getName()
	{
		return this->name;
	}
	void setColor(string color)
	{
		this->color = color;
	}
	string getColor()
	{
		return this->color;
	}
	void setSides(int side)
	{
		this->sides = side;
	}
	int getSides()
	{
		return this->sides;
	}
	void changeName(string newName)
	{
		this->name = newName;
	}
	void changeColor(string newcolor)
	{
		this->color = newcolor;
	}
	virtual double primeter()
	{
		double primeter = 0;
		for (int i = 0; i < sides; i++)
			primeter+= positoin[i].distance(positoin[(i + 1) % sides]);
		return primeter;
	}
	virtual double area()
	{
		return 0;
	}
	void show()
	{
		cout << "\nName: " << getName() << "\nColor: " << getColor() << "\nPrimeter = " << primeter() << "\nArea = " << area() << "\nPoints : ";
		for (int i = 0; i < getSides(); i++)
			cout << positoin[i] << "\t";
	}

};
class Rectangular: public Shape
{
public:
	Rectangular(Point *recPosition) :Shape("Rectanglur", "Blue", recPosition,4)
	{
		/*for (int i = 0; i < getSides(); i++)
			positoin[i] = recPosition[i];*/
	}
	Rectangular(Point p1, Point p2, Point p3, Point p4) :Shape("Rectanglur", "Blue",nullptr, 4)
	{
		positoin=new Point[4];
		positoin[0] = p1;
		positoin[1] = p2;
		positoin[2] = p3;
		positoin[3] = p4;
	}
	virtual double area()
	{
		double side1 = positoin[0].distance(positoin[1]);
		double side2 = positoin[1].distance(positoin[2]);
		return side1*side2;
	}
};
class Circle : public Shape
{
public:
	Circle(Point *cirPosition) :Shape("Circle", "Red", cirPosition, 2)
	{
		
	}
	Circle(Point p1, Point p2) :Shape("Circle", "Red", nullptr, 2)
	{
		positoin=new Point[2];
		positoin[0] = p1;
		positoin[1] = p2;
	}
	virtual double area()
	{
		double radius = positoin[0].distance(positoin[1]);
		return radius*radius*3.14;
	}
	virtual double primeter()
	{
		double radius = positoin[0].distance(positoin[1]);
		return 2*radius*3.14;
	}
};
class Triangle : public Shape
{
public:
	Triangle(Point *triPosition) :Shape("Triangle", "Black", triPosition, 3)
	{
	}
	Triangle(Point p1, Point p2, Point p3) :Shape("Triangle", "Black", nullptr, 3)
	{
		positoin=new Point[3];
		positoin[0] = p1;
		positoin[1] = p2;
		positoin[2] = p3;
	}
	virtual double area()
	{
		double p = primeter() / 2;
		return sqrt(p*(p - positoin[0].distance(positoin[1]))*
			(p - positoin[0].distance(positoin[2]))*
			(p - positoin[1].distance(positoin[2])));
	}
};
class Lozenge : public Shape
{
public:
	Lozenge(Point *lozPosition) :Shape("Lozenge", "Yellow", lozPosition, 4)
	{
	}
	Lozenge(Point p1, Point p2, Point p3, Point p4) :Shape("Lozenge", "Yellow", nullptr, 4)
	{
		positoin=new Point[4];
		positoin[0] = p1;
		positoin[1] = p2;
		positoin[2] = p3;
		positoin[3] = p4;
	}
	virtual double area()
	{
		double p = primeter() / 2;
		return 2*sqrt(p*(p - positoin[0].distance(positoin[1]))*
			(p - positoin[0].distance(positoin[2]))*
			(p - positoin[1].distance(positoin[2])));
	}
};
class Trapezoid : public Shape
{
public:
	Trapezoid(Point *trapPosition) :Shape("Trapezoid", "Green", trapPosition, 4)
	{
		for (int i = 0; i < getSides(); i++)
			positoin[i] = trapPosition[i];
	}
	Trapezoid(Point p1, Point p2, Point p3, Point p4) :Shape("Trapezoid", "Green", nullptr, 4)
	{
		positoin=new Point[4];
		positoin[0] = p1;
		positoin[1] = p2;
		positoin[2] = p3;
		positoin[3] = p4;
	}
	virtual double area()
	{
		return 0;
	}
};


ostream & operator<<(ostream & o1, Point p)
{
	cout << "(" << p.getX() << "," << p.getY() << ")";
	return o1;
}

int main()
{
	Point p1(2, 2), p2(8, 5), p3(-7, -2), p4(9, -9);
	Point * p4points = new Point[4];
	p4points[0].setX(2); p4points[0].setY(0);
	p4points[1].setX(8); p4points[1].setY(-5);
	p4points[2].setX(7); p4points[2].setY(5);
	p4points[3].setX(9); p4points[3].setY(-2);
	Shape **shape1 = new Shape *[6];
	shape1[0] = new Shape("alex","jane",p4points,4);
	shape1[1] = new Rectangular(p4points);
	shape1[2] = new Lozenge(p4points); 
	shape1[3] = new Trapezoid(p4points);
	shape1[4] = new Triangle(p1, p2, p3);
	shape1[5] = new Circle(p1,p2);
	for (int i = 0; i < 6; i++)
		shape1[i]->show();
	cout << endl;
	shape1[0]->changeName("5sides");
	shape1[1]->changeColor("brown");
	shape1[0]->show();
	shape1[1]->show();

	system("pause");
	return 0;
}
