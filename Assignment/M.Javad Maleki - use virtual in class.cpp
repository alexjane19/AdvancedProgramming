#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
class CommEmployee
{
private:
	string firstName;
	string lastName;
	string id;
	double grossSales; 
	double commissionRate;
public:
	CommEmployee(const string &first, const string &last, const string &id, double sale=0.0, double rate=0.0)
		:firstName(first), lastName(last), id(id)
	{
		setGrossSales(sale); 
		setCommRate(rate);
	}

	void setFirstName(const string &first)
	{
		firstName = first;
	}
	string getFirstName() 
	{
		return firstName;
	}
	void setLastname(const string &last)
	 {
		lastName = last;
	}
	string getLastName() 
	{
		return lastName;
	}
	void setId(const string &id)
	{
		this->id = id;
	}
	string getId() 
	{
		return this->id;
	}
	void setGrossSales(const double &sale)
	{
		grossSales = (sale < 0.0) ? 0.0 : sale;
	}
	double getGrossSales() 
	{
		return grossSales;
	}
	void setCommRate(const double &rate)
	{
		commissionRate = (rate > 0.0 && rate < 1.0) ? rate : 0.0;
	}
	double getCommRate() 
	{
		return commissionRate;
	}
	virtual double earning()
	{
		return getGrossSales() * getCommRate();
	}
	virtual void print()
	{
		cout << "\nCommission employee : " << getFirstName() << " " << getLastName() << "\nID : " << getId()
			 << "\nGross Sales : " << getGrossSales() << "\nCommission Rate : " << getCommRate() ;
	}

	~CommEmployee(){}
};

class BasePlusCommEmployee : public CommEmployee
{
private:
	double baseSalary;
public:
	BasePlusCommEmployee(const string &first, const string &last, const string &id, double sale=0.0 , double rate=0.0 , double salary=0.0 ) 
		:CommEmployee (first, last, id, sale, rate) 
	{ setBaseSalary(salary); }
	
	void setBaseSalary(double salary){
		baseSalary = (salary < 0.0) ? 0.0 : salary;
	}
	double getBaseSalary() 
	{
		return baseSalary;
	}
	virtual double earning()
	{
		return getBaseSalary() + CommEmployee::earning();
	}
	virtual void print()
	{
		CommEmployee::print();
		cout << "\nBase Salary : " << getBaseSalary();
	}
	~BasePlusCommEmployee(){}

int main()
{
	CommEmployee *cep = new CommEmployee("Johnny", "Cage", "10102555", 1000.0, 0.8);
	CommEmployee *cepe = new BasePlusCommEmployee("Alex","Jane","10102560",1100.0,0.3,3000.0);

	cep->print();
	cout << endl;
	
	cepe->print();
	cout << endl;

	cout <<"\nGrossSales * CommissionRate= "<<cep->earning()<<endl<<"BaseSalary + GrossSales * CommissionRate= "<<cepe->earning()<<endl;

	system("pause");
	return 0;
}

