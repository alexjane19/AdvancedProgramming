#include <iostream>
#include "extern.h"

using namespace std;

namespace alex
{
	
	template<class T>class complex
	{
		private:
			T real;
			T mag;
		public:
			template<class T>complex(T rea=0,T ma=0):real(rea),mag(ma){}

			friend istream & operator>>(istream & is1,complex & digit);

			friend ostream & operator<<(ostream & o1,complex &digit);
	};
	
istream & operator>>(istream & is1,complex<int> & digit)
			{
				cout<<"real num: ";
				is1>>digit.real;
				cout<<"mag num:";
				is1>>digit.mag;
				return is1;
			}
ostream & operator<<(ostream & o1, complex<int> &digit)
			{
				o1<<digit.real;
				cout<<"+";
				o1<<digit.mag;
				cout<<"i";
				return o1;
			}
	
}


int globalVaribel;
int main(int argc, char** argv) {
	
	globalVaribel=5;
	
	printglobal();

	alex::complex<int>t(9,6);
	
	cout<<t;

	return 0;
}
