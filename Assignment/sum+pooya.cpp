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

void display (double *&coe, int *&exp,int m)
{
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

void sum()
{
	int m,m1,m2,*exp=0,*exp1=0,*exp2=0;
	double *coe=0,*coe1=0,*coe2=0;


	m1=inputpoly(coe1,exp1);
	m2=inputpoly(coe2,exp2);

	for(int i=0;i<m1;i++)
	{
		for(int j=0;j<m2;j++)
		{
			if(exp1[i]==exp2[j])
			{
				coe1[i]+=coe2[j];
				for(int z=j;z<m2-1;z++)
				{
					exp2[z]=exp2[z+1];
					coe2[z]=coe2[z+1];
				}
				m2--;
			}
		}
	}
	m=m1+m2;
	coe=new double [m];
		exp=new int [m];
	for(int i=0 ; i<m1;i++)
	{
		coe[i]=coe1[i];
		exp[i]=exp1[i];
	}
	for(int i=m1,j=0 ; j<m2;i++,j++)
	{
		coe[i]=coe2[j];
		exp[i]=exp2[j];
	}

	display(coe,exp,m);
}

int main()
{
	sum();
	cout<<endl;
	system("pause");
	return 0;
}