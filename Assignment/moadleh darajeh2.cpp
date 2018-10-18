#include<iostream>

using namespace std;

int inputpoly(double *&coe, int *&exp)
{
	int n;
	cout<<"How is the degree of the polynomial? ";
	cin>>n;
	if(n>0)
	{
		coe=new double [n];
		exp=new int [n];
		if(!coe)
			cout<<"error:coe isnot full";
		if(!exp)
			cout<<"error:exp isnot full";

		for(int i=0;i<n;i++)
		{
			cout<<"Coefficients of the polynomial "<<i+1<<": ";
			cin>>coe[i];
			cout<<"Degree polynomial "<<i+1<<": ";
			cin>>exp[i];
		}
	}
	return n;
}

void display ()
{
	int m,*exp=0;
	double *coe=0;

	m=inputpoly(coe ,exp);

	for(int i=0;i<m;i++)
	{
		if(exp[i]==1)
		{
			if(coe[i]!=0)
			{
				if(coe[i]==1)
				{
					if(i==0)
						cout<<"x";
					else
						cout<<"+"<<"x";
				}

				if(coe[i]==-1)
					cout<<"-x";

				if(coe[i]>0 && coe[i]!=1)
				{
					if(i==0)
						cout<<coe[i]<<"x"; 
					else
						cout<<"+"<<coe[i]<<"x";

				}
				if(coe[i]<0 && coe[i]!=-1)
					cout<<coe[i]<<"x";
			}
		}
		if(exp[i]>1)
		{
			if(coe[i]!=0)
			{
				if(coe[i]==1)
				{
					if(i==0)
						cout<<"x^"<<exp[i];
					else
						cout<<"+"<<"x^"<<exp[i];
				}

				if(coe[i]==-1)
					cout<<"-x^"<<exp[i];

				if(coe[i]>0 && coe[i]!=1)
				{
					if(i==0)
						cout<<coe[i]<<"x^"<<exp[i]; 
					else
						cout<<"+"<<coe[i]<<"x^"<<exp[i];

				}
				if(coe[i]<0 && coe[i]!=-1)
					cout<<coe[i]<<"x^"<<exp[i];
			}
		}
		if(exp[i]==0)
		{
			if(coe[i]!=0)
			{
				if(coe[i]==1)
				{
					if(i==0)
						cout<<"1";
					else
						cout<<"+"<<"1";
				}

				if(coe[i]==-1)
					cout<<"-1";

				if(coe[i]>0 && coe[i]!=1)
				{
					if(i==0)
						cout<<coe[i]; 
					else
						cout<<"+"<<coe[i];

				}
				if(coe[i]<0 && coe[i]!=-1)
					cout<<coe[i];
			}
		}
		
	}
}

int main()
{
	display();
	cout<<endl;
	system("pause");
	return 0;
}