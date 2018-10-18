#ifndef LONGNUMBER_H
#define LONGNUMBER_H

#include<iostream>
using std::ostream;
using std::istream;
class LongNumber
{
private:
	char *lnumstr;
	int *lnumint;
	int digit;

public:
	LongNumber();
	LongNumber(char *);
	LongNumber(const LongNumber &);
	void convertToInt();
	LongNumber convertToChar(int *, int );
	LongNumber & operator=(const LongNumber & );
	friend LongNumber operator+(LongNumber &, LongNumber & );
	friend LongNumber operator-(LongNumber &,LongNumber & );
	friend LongNumber operator/(LongNumber &,LongNumber & );
	friend LongNumber operator*(LongNumber &,LongNumber & );
	friend bool operator==( LongNumber &, LongNumber & );
	friend bool operator<( LongNumber &, LongNumber & );
	friend bool operator>( LongNumber &, LongNumber & );
	friend ostream & operator<<(ostream &,LongNumber & );
	friend istream & operator>>(istream &,LongNumber & );
};   
#endif

