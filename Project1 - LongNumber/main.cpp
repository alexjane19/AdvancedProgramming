#include<iostream>
#include "LongNumber.h"
using namespace std;

int main(){

	LongNumber a("8948944984");
	LongNumber b("33333");
	LongNumber c;
	while (1)
	{
		int i = -1;
		cout << "0.enter num\n1. =\n2. +\n3. -\n4. *\n5. /\n6. ==\n7. <\n8. >9.others\n10.exit\n";
		cin >> i;
		switch (i)
		{
		case 0:
			cout << "mikhay 2ta adad vared koni ya yekadad\n";
			int x;
			cin >> x;
			if (x == 1)
				cin >> a;
			if (x == 2)
			{
				cin >> a;
				cin >> b;
			}
			break;
		case 1:
			c = a;
			cout << "c= ";
			cout << c;
			break;
		case 2:
			c = a + b;
			cout << c;
			break;
		case 3:
			c = a - b;
			cout << c;
			break;
		case 4:
			c = a*b;
			cout << c;
			break;
		case 5:
			try
			{
				LongNumber comp("0");
				if (a == comp)
					throw "nmitavani 0/x koni";
				c = a / b;
				cout << c;
			}
			catch (const char* exp)
			{
				cout << exp<<endl;
			}
			break;
		case 6:

			if (a > b)
				cout << "a>b";
			else
				cout << "a<b";
			break;
		case 7:
			if (a > b)
				cout << "a>b";
			else
				cout << "a<b";
			break;
		case 8:
			if (a == b)
				cout << "a==b";
			else
				cout << "a!=b";
			break;
		case 10:
			exit(0);
			break;
		default:
			cout << "we love miss.shadkam";
			break;
		}

	}
	
	return 0;
}

///taghsim bar sefr dorst beshe
//adade  kochik taghsim bar bozorg beshe sefr