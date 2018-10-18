#pragma once
#include<math.h>
#include "LongNumber.h"
class Point
{
public:
	   LongNumber x, y,z;
	   Point(LongNumber, LongNumber, LongNumber);
	   //friend ostream & operator<<(ostream & o1, point a);
	   double distance(Point);
	~Point();
};

