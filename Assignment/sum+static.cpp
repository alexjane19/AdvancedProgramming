#include<iostream>
#include<conio.h>
using namespace std;
const int n=3;
void input(double [] ,int []);
void display(double [] ,int []);
void sum(double [] ,int [], double [] ,int []);
int main()
{
	cout<<"you can enter"<<n<<" term(s) at maximum\n";
	int e1[n],e2[n];
	double c1[n], c2[n];
	cout<<endl;
	cout<<"fill y1:\n";
	input(c1,e1);
	cout<<"fill y2:\n";
	input(c2,e2);

	sum(c1,e1,c2,e2);
	cout<<endl;
	system("pause");
	return 0;
}

void input(double coe[], int exp[])
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<"coe["<<i<<"]=";
		cin>>coe[i];
		cout<<"exp["<<i<<"]=";
		cin>>exp[i];
	}
}

void display(double coe[] , int exp[])
{
	int i;
	for(i=0;i<n;i++)
	{
		if(coe[i]!=0)
		{
			if(coe[i]>0)
			{
				cout<<"+";
				if(coe[i]!=1)
					cout<<coe[i];
			}
			if(coe[i]<0)
				cout<<coe[i];
			if(exp[i]>1)
				cout<<"x^"<<exp[i];
			if(exp[i]==1)
				cout<<"x";

		}
	}
}

void sum(double coe1[], int exp1[], double coe2[], int exp2[])
{
	int e[n], flag=0;
	double c[n];

	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			if(exp1[i]==exp2[j])
			{
				c[i]=coe1[i]+coe2[j];
				e[i]=exp1[i];
				flag=1;
			}
		}
		if(flag==0)
		{
			c[i]=coe1[i];
			e[i]=exp1[i];

		}
		flag==0;
	}
	cout<<"y1 + y2 :";
	display(c,e);


}
