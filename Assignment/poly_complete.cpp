#include<iostream>

using namespace std;

struct poly
{
	double *coe;
	int *exp;
	int n;
};

void error(const char *msg)
{
	cout << "error  :::::  ";
	cout << msg << endl;
}

poly input_poly()
{
	poly p1;
	cout << "How is the degree of the polynomial? ";
	cin >> p1.n;
	if (p1.n <= 0)
		error("You must be a number greater than zero");
	else
	{
		p1.coe = new double[p1.n];
		p1.exp = new int[p1.n];
		if (!p1.exp || !p1.coe)
			error("Memory error");
		else
		{
			for (int i = 0; i < p1.n; i++)
			{
				cout << "coe[" << i << "]: ";
				cin >> p1.coe[i];
				cout << "exp[" << i << "]: ";
				cin >> p1.exp[i];
			}
			return p1;
		}
	}
}

void print_poly(poly p1)
{
	for (int i = 0; i < p1.n; i++)
	{
		if (p1.exp[i] == 1)
		{
			if (p1.coe[i] != 0)
			{
				if (p1.coe[i] == 1)
				{
					if (i == 0)
						cout << "x";
					else
						cout << "+" << "x";
				}

				if (p1.coe[i] == -1)
					cout << "-x";

				if (p1.coe[i] > 0 && p1.coe[i] != 1)
				{
					if (i == 0)
						cout << p1.coe[i] << "x";
					else
						cout << "+" << p1.coe[i] << "x";

				}
				if (p1.coe[i]<0 && p1.coe[i] != -1)
					cout << p1.coe[i] << "x";
			}
		}
		if (p1.exp[i]>1)
		{
			if (p1.coe[i] != 0)
			{
				if (p1.coe[i] == 1)
				{
					if (i == 0)
						cout << "x^" << p1.exp[i];
					else
						cout << "+" << "x^" << p1.exp[i];
				}

				if (p1.coe[i] == -1)
					cout << "-x^" << p1.exp[i];

				if (p1.coe[i] > 0 && p1.coe[i] != 1)
				{
					if (i == 0)
						cout << p1.coe[i] << "x^" << p1.exp[i];
					else
						cout << "+" << p1.coe[i] << "x^" << p1.exp[i];

				}
				if (p1.coe[i] < 0 && p1.coe[i] != -1)
					cout << p1.coe[i] << "x^" << p1.exp[i];
			}
		}
		if (p1.exp[i] == 0)
		{
			if (p1.coe[i] != 0)
			{
				if (p1.coe[i] == 1)
				{
					if (i == 0)
						cout << "1";
					else
						cout << "+" << "1";
				}

				if (p1.coe[i] == -1)
					cout << "-1";

				if (p1.coe[i] > 0 && p1.coe[i] != 1)
				{
					if (i == 0)
						cout << p1.coe[i];
					else
						cout << "+" << p1.coe[i];

				}
				if (p1.coe[i] < 0 && p1.coe[i] != -1)
					cout << p1.coe[i];
			}
		}
	}
	if (p1.exp[p1.n] == 0)
		cout << "+c";
	cout << endl;
	
}

poly sum_poly(poly p1, poly p2)
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

poly multiply_poly(poly p1, poly p2)
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

poly derivative_poly(poly p1)
{
	for (int i = 0; i < p1.n; i++)
	{
		p1.coe[i] *= p1.exp[i];
		p1.exp[i] -= 1;
	}
	return p1;
}

poly integration_poly(poly p1)
{
	for (int i = 0; i < p1.n; i++)
	{
		p1.coe[i] /= (p1.exp[i] + 1);
		p1.exp[i] += 1;
	}

	p1.exp[p1.n] = 0;

	return p1;
}

double evaluation_poly(poly p1, int x)
{
	double retval = 0;

	for (int i = 0; i < p1.n; i++)
	{
		retval += p1.coe[i] * pow(x, p1.exp[i]);
	}

	return retval;
}

int main()
{
	poly p1, p2;
	int menu;

	while (true)
	{
		cout << "1.Input Poly\n2.Print Poly\n3.Sum 2 Polys\n4.Multiply 2 Polys\n5.Derivative Poly\n6.Integration Poly\n7.Evaluation Poly\n8.Exit\n"
			<< "Choose one menu: ";
		cin >> menu;
		system("cls");

		if (menu == 1)
		{
			p1 = input_poly();

			system("pause");
		}

		if (menu == 2)
		{
			print_poly(p1);

			system("pause");
		}

		if (menu == 3)
		{
			cout << "Enter 2 polys for sum:\n";
			p1 = input_poly();
			p2 = input_poly();
			print_poly(p1);
			print_poly(p2);
			cout << "Sum:  ";
			print_poly(sum_poly(p1, p2));

			system("pause");
		}

		if (menu == 4)
		{
			cout << "Enter 2 polys for Multiply:\n";
			p1 = input_poly();
			p2 = input_poly();
			print_poly(p1);
			print_poly(p2);
			cout << "Multiply:  ";
			print_poly(multiply_poly(p1, p2));

			system("pause");
		}

		if (menu == 5)
		{
			print_poly(p1);
			cout << "Derivative:  ";
			print_poly(derivative_poly(p1));

			system("pause");
		}

		if (menu == 6)
		{
			print_poly(p1);
			cout << "Integration:  ";
			print_poly(integration_poly(p1));

			system("pause");
		}

		if (menu == 7)
		{
			int x;
			cout << "Please select a value for x: ";
			cin >> x;
			print_poly(p1);
			cout << "Evaluation:  " << evaluation_poly(p1, x) << endl;

			system("pause");
		}

		if (menu == 8)
		{
			break;
		}
		system("cls");
	}

	return 0;
}
