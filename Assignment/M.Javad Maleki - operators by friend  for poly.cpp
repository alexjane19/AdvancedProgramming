#include<iostream>
#include<cstdlib>
using namespace std;

void error(const char *msg)
{
	cout << "error  :::::  ";
	cout << msg << endl;
}

class poly
{
private:
	double *coe;
	int *exp;
	int n;
public:

	poly()
	{
		coe = 0;
		exp = 0;
		n = 0;
	}

	void allocateMemory(int n)
	{
		this->coe = new double[this->n = n];
		this->exp = new int[this->n = n];
		if (!coe || !exp)
			error("Memory Allocation");
	}
	void input(void)
	{
		if (n > 0)
		{
			delete[]coe;
			delete[]exp;
			coe = 0;
			exp = 0;
			n = 0;
		}

		cout << "How is the degree of the polynomial? ";
		cin >> n;
		if (n <= 0)
			error("You must be a number greater than zero");
		else
		{
			allocateMemory(n);
			for (int i = 0; i < n; i++)
			{
				cout << "coe[" << i << "]: ";
				cin >> coe[i];
				cout << "exp[" << i << "]: ";
				cin >> exp[i];
			}
		}

	}

	void print(void)
	{
		for (int i = 0; i < n; i++)
		{
			if (exp[i] == 1)
			{
				if (coe[i] != 0)
				{
					if (coe[i] == 1)
					{
						if (i == 0)
							cout << "x";
						else
							cout << "+" << "x";
					}

					if (coe[i] == -1)
						cout << "-x";

					if (coe[i] > 0 && coe[i] != 1)
					{
						if (i == 0)
							cout << coe[i] << "x";
						else
							cout << "+" << coe[i] << "x";

					}
					if (coe[i]<0 && coe[i] != -1)
						cout << coe[i] << "x";
				}
			}
			if (exp[i]>1)
			{
				if (coe[i] != 0)
				{
					if (coe[i] == 1)
					{
						if (i == 0)
							cout << "x^" << exp[i];
						else
							cout << "+" << "x^" << exp[i];
					}

					if (coe[i] == -1)
						cout << "-x^" << exp[i];

					if (coe[i] > 0 && coe[i] != 1)
					{
						if (i == 0)
							cout << coe[i] << "x^" << exp[i];
						else
							cout << "+" << coe[i] << "x^" << exp[i];

					}
					if (coe[i] < 0 && coe[i] != -1)
						cout << coe[i] << "x^" << exp[i];
				}
			}
			if (exp[i] == 0)
			{
				if (coe[i] != 0)
				{
					if (coe[i] == 1)
					{
						if (i == 0)
							cout << "1";
						else
							cout << "+" << "1";
					}

					if (coe[i] == -1)
						cout << "-1";

					if (coe[i] > 0 && coe[i] != 1)
					{
						if (i == 0)
							cout << coe[i];
						else
							cout << "+" << coe[i];

					}
					if (coe[i] < 0 && coe[i] != -1)
						cout << coe[i];
				}
			}
		}
		cout << endl;
	}
	~poly()
	{
		delete[]coe;
		delete[]exp;
		coe = 0; exp = 0; n = 0;
	}

	void sort()
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - 1 - i; j++)
			if (exp[j] < exp[j + 1])
			{
				swap(exp[j], exp[j + 1]);
				swap(coe[j], coe[j + 1]);
			}

		}

	}
	poly(const poly &a)
	{
		coe = new double[n = a.n];
		exp = new int[n = a.n];
		for (int i = 0; i < n; i++)
		{
			coe[i] = a.coe[i];
			exp[i] = a.exp[i];
		}
	}
	poly &operator=(const poly &a)
	{
		if (n < 0)
		{
			delete[]coe;
			delete[]exp;
			coe = 0; exp = 0; n = 0;
		}
		coe = new double[n = a.n];
		exp = new int[n = a.n];

		for (int i = 0; i < n; i++)
		{
			coe[i] = a.coe[i];
			exp[i] = a.exp[i];
		}
		return *this;
	}
	
	friend poly operator+(const poly &a, const poly &b);
	friend poly operator*(const poly &a, const poly &b);
};

poly operator+(const poly &a, const poly &b)
{
	int n1, bn = b.n;
	for (int i = 0; i < a.n; i++)
	{
		for (int j = 0; j < bn; j++)
		{
			if (a.exp[i] == b.exp[j])
			{
				a.coe[i] += b.coe[j];
				for (int z = j; z < bn - 1; z++)
				{
					b.exp[z] = b.exp[z + 1];
					b.coe[z] = b.coe[z + 1];
				}
				bn--;
			}
		}
	}
	poly sum;
	n1 = a.n + bn;
	sum.allocateMemory(n1);

	for (int i = 0, j = 0; i < sum.n; i++, j++)
	{
		if (i < a.n)
		{
			sum.coe[i] = a.coe[j];
			sum.exp[i] = a.exp[j];
		}

		if (i == a.n)
			j = 0;

		if (i >= a.n)
		{

			sum.coe[i] = b.coe[j];
			sum.exp[i] = b.exp[j];

		}
	}
	return sum;
}

poly operator*(const poly &a, const poly &b)
{
	int n1;
	n1 = a.n*b.n;
	poly multi;
	multi.allocateMemory(n1);
	int count = 0;

	for (int i = 0; i < a.n; i++)
	{
		for (int j = 0; j < b.n; j++)
		{
			multi.coe[count] = a.coe[i] * b.coe[j];
			multi.exp[count] = a.exp[i] + b.exp[j];
			count++;
		}
	}

	for (int i = 0; i < multi.n; i++)
	{
		for (int j = i + 1; j < multi.n; j++)
		{
			if (multi.exp[i] == multi.exp[j])
			{
				multi.coe[i] += multi.coe[j];
				for (int z = j; z < multi.n - 1; z++)
				{
					multi.exp[z] = multi.exp[z + 1];
					multi.coe[z] = multi.coe[z + 1];
				}
				multi.n--;
				j--;
			}
		}
	}

	return multi;
}



int main()
{
	poly p1, p2, p3, sum, multi;
	p1.input();
	p2.input();
	cout << "=\n";
	p3 = p1;
	p3.print();
	cout << "+\n";
	sum = p1 + p2;
	sum.sort();
	sum.print();
	cout << "*\n";
	multi = p1*p2;
	multi.sort();
	multi.print();
	cout << "p1\n";
	p1.print();
	cout << "p2\n";
	p2.print();
	
	system("pause");
	return 0;
}

