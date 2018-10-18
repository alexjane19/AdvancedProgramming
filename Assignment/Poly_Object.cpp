#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

void error(const char *msg)
{
	cout << "error  :::::  ";
	cout << msg << endl;
}

struct poly
{
	double *coe;
	int *exp;
	int n;

	void input()
	{
		cout << "How is the degree of the polynomial? ";
		cin >> n;
		if (n <= 0)
			error("You must be a number greater than zero");
		else
		{
			coe = new double[n];
			exp = new int[n];
			if (!exp || !coe)
				error("Memory error");
			else
			{
				for (int i = 0; i < n; i++)
				{
					cout << "coe[" << i << "]: ";
					cin >> coe[i];
					cout << "exp[" << i << "]: ";
					cin >> exp[i];
				}
			}
		}
	}

	void print()
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
		if (exp[n] == 0)
			cout << "+c";
		cout << endl;

	}

	poly sum(poly p1, poly p2)
	{
		poly sum;
		for (int i = 0; i < p1.n; i++)
		{
			for (int j = 0; j < p2.n; j++)
			{
				if (p1.exp[i] == p2.exp[j])
				{
					p1.coe[i] += p2.coe[j];
					for (int z = j; z < p2.n - 1; z++)
					{
						p2.exp[z] = p2.exp[z + 1];
						p2.coe[z] = p2.coe[z + 1];
					}
					p2.n--;
				}
			}
		}
		sum.n = p1.n + p2.n;
		sum.coe = new double[sum.n];
		sum.exp = new int[sum.n];


		for (int i = 0, j = 0; i < sum.n; i++, j++)
		{
			if (i < p1.n)
			{
				sum.coe[i] = p1.coe[j];
				sum.exp[i] = p1.exp[j];
			}

			if (i == p1.n)
				j = 0;

			if (i >= p1.n)
			{

				sum.coe[i] = p2.coe[j];
				sum.exp[i] = p2.exp[j];

			}
		}
		for (int i = 0; i < sum.n - 1; i++)
		{
			for (int j = 0; j < sum.n - 1 - i; j++)
			if (sum.exp[j] < sum.exp[j + 1])
			{
				swap(sum.exp[j], sum.exp[j + 1]);
				swap(sum.coe[j], sum.coe[j + 1]);
			}

		}
		return sum;
	}

	poly multiply(poly p1, poly p2)
	{
		poly multi;
		multi.n = p1.n*p2.n;
		int count = 0;

		multi.coe = new double[multi.n];
		multi.exp = new int[multi.n];

		for (int i = 0; i < p1.n; i++)
		{
			for (int j = 0; j < p2.n; j++)
			{
				multi.coe[count] = p1.coe[i] * p2.coe[j];
				multi.exp[count] = p1.exp[i] + p2.exp[j];
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

	void derivative()
	{
		for (int i = 0; i < n; i++)
		{
			coe[i] *= exp[i];
			exp[i] -= 1;
		}
	}

	void integration()
	{
		for (int i = 0; i < n; i++)
		{
			coe[i] /= (exp[i] + 1);
			exp[i] += 1;
		}

		exp[n] = 0;

	}

	double evaluation(int x)
	{
		double retval = 0;

		for (int i = 0; i < n; i++)
		{
			retval += coe[i] * pow(x, exp[i]);
		}

		return retval;
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

	void addterm()
	{
		cout << "AddTerm:\n";
		cout << "coe[" << n << "]: ";
		cin >> coe[n];
		cout << "exp[" << n << "]: ";
		cin >> exp[n];
		n++;
	}

	void search()
	{
		int srh_exp;
		cin >> srh_exp;
		for (int i = 0; i < n; i++)
		{
			if (srh_exp == exp[i])
			{
				cout << coe[i] << "x^" << exp[i] << endl;
			}
		}
	}

};

int main()
{
	poly p1, p2, sum, multi;
	int menu;

	while (true)
	{
		cout << "1.Input Poly\n2.Print Poly\n3.Sum 2 Polys\n4.Multiply 2 Polys\n5.Derivative Poly\n6.Integration Poly\n7.Evaluation Poly\n8.AddTerm\n9.Search\n10.Exit\n"
			<< "Choose one menu: ";
		cin >> menu;
		system("cls");

		if (menu == 1)
		{
			p1.input();
			p1.sort();

			system("pause");
		}

		if (menu == 2)
		{
			p1.print();

			system("pause");
		}

		if (menu == 3)
		{
			cout << "Enter 2 polys for sum:\n";
			p1.input();
			p2.input();
			p1.sort();
			p2.sort();
			p1.print();
			p2.print();
			cout << "Sum:  ";
			sum.sum(p1, p2).print();


			system("pause");
		}

		if (menu == 4)
		{
			cout << "Enter 2 polys for Multiply:\n";
			p1.input();
			p2.input();
			p1.sort();
			p2.sort();
			p1.print();
			p2.print();
			cout << "Multiply:  ";

			multi.multiply(p1, p2).print();

			system("pause");
		}

		if (menu == 5)
		{
			p1.input();
			p1.sort();
			p1.print();
			cout << "Derivative:  ";
			p1.derivative();
			p1.print();

			system("pause");
		}

		if (menu == 6)
		{
			p1.input();
			p1.sort();
			p1.print();
			cout << "Integration:  ";
			p1.integration();
			p1.print();

			system("pause");
		}

		if (menu == 7)
		{
			int x;
			cout << "Please select a value for x: ";
			cin >> x;
			p1.input();
			p1.sort();
			p1.print();
			cout << "Evaluation:  " << p1.evaluation(x) << endl;

			system("pause");
		}

		if (menu == 8)
		{
			p1.addterm();
			p1.sort();
			p1.print();

			system("pause");
		}
		if (menu == 9)
		{
			p1.search();

			system("pause");
		}
		if (menu == 10)
		{
			break;
		}
		system("cls");
	}

	return 0;
}

