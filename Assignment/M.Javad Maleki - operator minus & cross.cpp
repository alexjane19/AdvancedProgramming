#include <iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
void error(const char*);
class array{private: double *a;	int n; //static int number_of_var;
  public: array(){n=0; a=0;cout<<"default constructor\n";}
    array(const int n1){allocateMemory(n1);} 
    void allocateMemory(int n1){
      this->a = new double [this->n = n1 ]; // (*this).a
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
    if(n>0){delete[] a;a=0;n=0;}
		cout<<"Enter number of terms"; 
		cin>> n;
		allocateMemory(n);
		for(int i=0; i<n ; i++){
			cout<<"Enter a["<<i<<"]: " ; 
			cin >> a[i];
		}
	}
	void print(void){
		for(int i=0; i < n; i++)
			cout << a[i] <<endl;
	}
	~array(){delete[]a; a=0;n=0;}
	bool resize(int n1){ 
		double*a1;a1=a; int i;
		a = new double[n1];
		for(i=0;i<n && i<n1;i++) a[i]=a1[i];
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
  array & operator=(const array & t){
    if(n > 0) delete[] a;
    a  = new double[ n = t.n];
    for(int i=0;i<n;i++) a[i]=t.a[i];
    return *this;
  }
	array(const array &b){
    cout<<"copy constructor "<<b.n<<endl;
    a=new double[n=b.n];
    for(int i=0; i<n; i++) 
      a[i]=b.a[i];
  }
  array operator+(const array & a){int n1,i;
    array res(n1 = a.n > this->n ? a.n : this->n);
    for(i=0;i < (a.n < this->n ? a.n : this->n);i++)
      res.a[i] = a.a[i] + this->a[i];
    double *pa= a.n > this->n ? a.a : this->a;
    for(;i<n1;i++) res.a[i]=*(pa+i);
    return res;
  }
  array operator-(const array & a){
	  int n1, i;
	  array res(n1 = a.n > this->n ? a.n : this->n);
	  for (i = 0; i < (a.n < this->n ? a.n : this->n); i++)
		  res.a[i] = a.a[i] - this->a[i];
	  double *pa = a.n > this->n ? a.a : this->a; 
	  for (; i<n1; i++) res.a[i] = *(pa + i);
	  return res;
  }
  array operator*(const array & a){
	  int n1, i;
	  array res(n1 = a.n > this->n ? a.n : this->n);
	  for (i = 0; i < (a.n < this->n ? a.n : this->n); i++)
		  res.a[i] = a.a[i] * this->a[i];
	  double *pa = a.n > this->n ? a.a : this->a;
	  for (; i<n1; i++) res.a[i] = *(pa + i);
	  return res;
  }
};
int main(){
	array m2(4),m3(5), m4(2),m5(2),m6(2); m2.input();m3.input();
  m4 = m2;
  m4 = m2 + m3 + m2;// m4.operator=(m2.operator+(m3))
  m5 = m2 - m3;
  m6 = m2 * m3;
  cout << "+\n";
  m4.print();
  cout << "-\n";
  m5.print();
  cout << "*\n";
  m6.print();
  cout << endl;
  system("pause");
  return 0;
}
void error(const char *msg)
{cout<<"error  :::::  ";	cout<<msg<<endl;	exit(0);}

