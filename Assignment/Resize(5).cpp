#include <iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
void error(const char*);
class array{	
  private:
	double *a;	
	int n;
  public:
    void allocateMemory(int n1){
		a = new double [n=n1];
		if(!a) error("Memory allocation ");
	}
	void change(int index, double val){
		if(index<n)		a[index]= val;
		else error("illegal address");
	}
	double get(int index){
		if(index <n )		return a[index];
		else error("Illegal address");
		return 0;
	}
	void input(void){
		cout<<"Enter number of terms"; 
		cin>> n;
		allocateMemory(n);
		for(int i=0; i<n; i++){
			cout<<"Enter a["<<i<<"]: " ; 
			cin >> a[i];
		}
	}
	void print(void){
		for(int i=0; i < n; i++)
			cout << a[i] <<endl;
	}
	void destruct(void){delete[]a; a=0;n=0;}

	bool resize(int n1){ 
		double*a1;
		int i;
		a1=a;
		a = new double[n1];
		for(i=0;i<n && i<n1;i++) 
			a[i]=a1[i];
		n=n1;

		delete[] a1;

		return true;
	}
	int search(double x){
		int i;
		for(i=0;i<n;i++)
			if(x==a[i]) return i;
		return -1;
	}
	void sort(void){
		int i,j;
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				if(a[i]>a[j]){
					double temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
	}
};

int main(){
	array m1;
	m1.input();
	m1.print();
	m1.resize(5);
	m1.print();
	m1.input();
	system("pause");
	m1.destruct();
	return 0;
}
void error(const char *msg)
{cout<<"error  :::::  ";	cout<<msg<<endl;	exit(0);}
