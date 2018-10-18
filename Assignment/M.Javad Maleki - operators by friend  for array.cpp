#include <iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
void error(const char*);
class array{private: double *a;	int n;
public:
	array(){ n = 0; a = 0; }
	array(const int n1){ a = new double[n = 1]; a[0] = n1; }
	void allocateMemory(int n1){
		this->a = new double [this->n = n1]; // (*this).a
		if (!a) error("Memory allocation ");
	}
	void change(int index, double val){
		if (index<n)		a[index] = val;
		else error("illegal address");
	}
	double get(int index){
		if (index <n)		return a[index];
		else error("Illegal address");
		return 0;
	}
	void input(void){
		if (n>0){ delete[] a; a = 0; n = 0; }
		cout << "Enter number of terms";
		cin >> n;
		allocateMemory(n);
		for (int i = 0; i<n; i++){
			cout << "Enter a[" << i << "]: ";
			cin >> a[i];
		}
	}
	void print(void){
		for (int i = 0; i < n; i++)
			cout << a[i] << endl;
	}
	~array(){ delete[]a; a = 0; n = 0; }
	bool resize(int n1){
		double*a1; a1 = a; int i;
		a = new double[n1];
		for (i = 0; i<n && i<n1; i++) a[i] = a1[i];
		n = n1;
		delete[] a1;
		return true;
	}
	int search(double x){
		int i;
		for (i = 0; i<n; i++)
		if (x == a[i]) return i;
		return -1;
	}
	void sort(void){
		int i, j;
		for (i = 0; i<n - 1; i++)
		for (j = i + 1; j<n; j++)
		if (a[i]>a[j]){
			double temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	array & operator=(const array & t){
		if (n > 0) delete[] a;
		a = new double[n = t.n];
		for (int i = 0; i<n; i++) a[i] = t.a[i];
		return *this;
	}
	array(const array &b){
		//cout<<"copy "<<b.n<<endl;
		a = new double[n = b.n];
		for (int i = 0; i<n; i++)
			a[i] = b.a[i];
	}
	array & operator+=(const array & t){
		*this = *this + t;
		return *this;
	}
	friend array operator+(const array & a, const array & b);
	friend array operator-(const array & a, const array & b);
	friend array operator*(const array & a, const array & b);
	friend array operator/(const array & a, const array & b);
	friend bool operator==(const array & a, const array & b);
	friend bool operator>(const array & a, const array & b);
	friend bool operator<(const array & a, const array & b);
};

bool operator==(const array & a, const array & b){
	if (a.n == b.n){
		for (int i = 0; i<a.n; i++)
		if (a.a[i] != b.a[i]) return false;
	}
	else return false;
	return true;
}
bool operator>(const array & a, const array & b){
	if (a.n > b.n){
		for (int i = 0; i<a.n; i++)
		if (a.a[i] < b.a[i]) return false;
	}
	else return false;
	return true;
}
bool operator<(const array & a, const array & b){
	if (a.n < b.n){
		for (int i = 0; i<a.n; i++)
		if (a.a[i] > b.a[i]) return false;
	}
	else return false;
	return true;
}
array operator+(const array & a, const array & b){
	int n1, i;
	n1 = (a.n > b.n) ? a.n : b.n;
	array res; res.allocateMemory(n1);
	for (i = 0; i < (a.n < b.n ? a.n : b.n); i++)
		res.a[i] = a.a[i] + b.a[i];
	double *pa = (a.n > b.n) ? a.a : b.a;
	for (; i<n1; i++) res.a[i] = *(pa + i);
	return res;
}
array operator-(const array & a, const array & b){
	int n1, i;
	n1 = (a.n > b.n) ? a.n : b.n;
	array res; res.allocateMemory(n1);
	for (i = 0; i < (a.n < b.n ? a.n : b.n); i++)
		res.a[i] = a.a[i] - b.a[i];
	double *pa = (a.n > b.n) ? a.a : b.a;
	for (; i<n1; i++) res.a[i] = *(pa + i);
	return res;
}
array operator*(const array & a, const array & b){
	int n1, i;
	n1 = (a.n > b.n) ? a.n : b.n;
	array res; res.allocateMemory(n1);
	for (i = 0; i < (a.n < b.n ? a.n : b.n); i++)
		res.a[i] = a.a[i] * b.a[i];
	double *pa = (a.n > b.n) ? a.a : b.a;
	for (; i<n1; i++) res.a[i] = *(pa + i);
	return res;
}
array operator/(const array & a, const array & b){
	int n1, i;
	n1 = (a.n > b.n) ? a.n : b.n;
	array res; res.allocateMemory(n1);
	for (i = 0; i < (a.n < b.n ? a.n : b.n); i++)
		res.a[i] = a.a[i] / b.a[i];
	double *pa = (a.n > b.n) ? a.a : b.a;
	for (; i<n1; i++) res.a[i] = *(pa + i);
	return res;
}
int main(){
	array m2, m3, m4;
	m2.input();
	m3.input();
	cout << "+ \n"; 
	m4 = m2 + m3;
	m4.print();
	cout << "- \n";
	m4 = m2 - m3;
	m4.print();
	cout << "* \n"; 
	m4 = m2 * m3;
	m4.print();
	cout << "/ \n"; 
	m4 = m2 / m3;
	m4.print();
	if (m2 > m3) cout << ">" << endl;
	else cout << "<" << endl;
	if (m2 < m3) cout << "<" << endl; 
	else cout << ">" << endl;
	if (m2 == m4) cout << "==" << endl; else cout << "!=" << endl;
	m2 = m4;
	if (m2 == m4) cout << "==" << endl; else cout << "!=" << endl;
	system("pause");
	return 0;
}
void error(const char *msg)
{
	cout << "error  :::::  ";	cout << msg << endl;	exit(0);
}

