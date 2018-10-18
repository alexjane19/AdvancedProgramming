
#include<iostream>
#include<string>
#include<iomanip>
#include"LongNumber.h"

using namespace std;

namespace comp
{
	bool compare(int *copDenominator, int *dividen, int min, int z, int minL)
	{
		bool bl = false;
		for (int i = z, j = 0; i<min; i++, j++)
		{
			if (copDenominator[0] != 0 && minL>min - z - 1)
			{
				bl = true;
				break;
			}
			if (copDenominator[j] == 0 && (min - z) == minL)
				j++;
			if (copDenominator[j] == dividen[i])
				continue;
			if (copDenominator[j] > dividen[i])
				bl = true;
			if (copDenominator[j] < dividen[i])
				break;
		}
		return bl;
	}
}

LongNumber::LongNumber()
	{
		if (digit>0)
			delete[] this->lnumstr;
		if (digit>0)
			delete[] this->lnumint;
		digit = 0;
	}

LongNumber::LongNumber(char *lnumstr)
	{
		if (digit>0)
			delete[] this->lnumstr;

		digit = strlen(lnumstr);

		this->lnumstr = new char[digit];
		this->lnumstr = lnumstr;
		//	strcmp(this->lnumstr,lnumstr);


	}

LongNumber::LongNumber(const LongNumber &cop)
	{
		lnumstr = new char[digit = cop.digit];
		//lnumstr[digit]='\0';
		//for(int i=0;i<digit;i++)
		lnumstr/*[i]*/ = cop.lnumstr/*[i]*/;
	}
	//~LongNumber()
	//{
	//	if (digit>0)
	//		delete lnumstr;
	//	if (digit>0)
	//		delete lnumint;
	//	digit = 0;
	//}

void LongNumber::convertToInt()
	{
		/*if(lnumint)
		delete [] lnumint; */


		lnumint = new int[digit];

		for (int i = 0, j = 0; i<digit; i++)
		{
			lnumint[i] = lnumstr[i] - '0';
		}
	}
LongNumber LongNumber::sqr()
{
		int i;
		LongNumber temp, temp1, temp2, a0,add2("2");
		i = (this->digit) * 100;
		//num_to_str(a0, i);
		while (1){
			temp = (*this / a0 + a0) / add2;
			temp2 = (*this / temp + temp) / add2;
			if (temp == temp2)
				break;
			a0 = temp;
			temp = temp2;
		}
		return temp2;
}
LongNumber LongNumber::convertToChar(int *numint, int digitint)
	{
		//if(digit>0)
		//delete [] lnumstr;
	int z;
	for (z = 0; z < digitint; z++)
	{
		if (numint[z] == 0)
			continue;
		digitint -= z;
		break;
	}
		this->digit = digitint;
		lnumstr = new char[digit];
		lnumstr[digit] = '\0';
		for (int i = z, j = 0; j<this->digit; i++,j++)
			this->lnumstr[j] = numint[i] + '0';

		delete[] numint;

		return *this;
	}

LongNumber & LongNumber::operator=(const LongNumber & num)
	{
		//if(digit>0) 
		//delete [] lnumstr;
		digit = num.digit;
		lnumstr = new char[digit];
		lnumstr[digit] = '\0';
		for (int i = 0; i<digit; i++)
			lnumstr[i] = num.lnumstr[i];
		return *this;
	}


LongNumber operator+(LongNumber & num1, LongNumber & num2)
{
	num1.convertToInt();
	num2.convertToInt();

	int result, i, j, z;
	int max_result = (num1.digit > num2.digit) ? num1.digit : num2.digit;
	int min_result = (num1.digit < num2.digit) ? num1.digit : num2.digit;
	result = max_result;

	if (num1.digit == num2.digit)
		result = num1.digit + 1;

	int *resultNum = new int[result];
	memset(resultNum, 0, 4 * result);

	for (z = result - 1, i = max_result - 1, j = min_result - 1; j >= 0; z--, i--, j--)
	{
		resultNum[z] += (num1.digit > num2.digit) ? (num1.lnumint[i] + num2.lnumint[j]) : (num1.lnumint[j] + num2.lnumint[i]);
		if (resultNum[z] >= 10)
		{
			if (z != 0)
				resultNum[z - 1] = resultNum[z] / 10;
			resultNum[z] = resultNum[z] % 10;

		}
	}

	for (; i >= 0; i--)
		resultNum[i] += (num1.digit > num2.digit) ? num1.lnumint[i] : num2.lnumint[i];

	LongNumber resultstr;
	resultstr.convertToChar(resultNum, result);
	return resultstr;
}

LongNumber operator-(LongNumber & num1, LongNumber & num2)
{

	num1.convertToInt();
	num2.convertToInt();
	int max_result, min_result,*maxresult,*minresult;
	if (num1.digit == num2.digit)
	{
		for (int i = 0; i<num1.digit; i++)
		{
			if (num1.lnumint[i] == num2.lnumint[i])
				continue;
			if (num1.lnumint[i]>num2.lnumint[i])
			{
				max_result = num1.digit;
				min_result = num2.digit;
				maxresult = num1.lnumint;
				minresult = num2.lnumint;
				break;
			}

			if (num1.lnumint[i]<num2.lnumint[i])
			{
				max_result = num2.digit;
				min_result = num1.digit;
				maxresult = num2.lnumint;
				minresult = num1.lnumint;
				break;
			}
		}
	}
	else
	{
		max_result = (num1.digit > num2.digit) ? num1.digit : num2.digit;
		min_result = (num1.digit < num2.digit) ? num1.digit : num2.digit;
		maxresult = (num1.digit > num2.digit) ? num1.lnumint : num2.lnumint;
		minresult = (num1.digit < num2.digit) ? num1.lnumint : num2.lnumint;
	}
	int i, j;

	int *resultNum = new int[max_result];
	memset(resultNum, 0, 4 * max_result);

	for (i = max_result - 1, j = min_result - 1; j >= 0; i--, j--)
	{
		resultNum[i] += maxresult[i] - minresult[j];
		if (resultNum[i]<0)
		{
			if (i != 0)
				resultNum[i - 1] = -1;
			resultNum[i] = (10 + resultNum[i]);

		}
	}
	for (; i >= 0; i--)
		resultNum[i] += maxresult[i];

	LongNumber resultstr;
	resultstr.convertToChar(resultNum, max_result);
	return resultstr;
}

LongNumber operator*(LongNumber & num1, LongNumber & num2)
{
	num1.convertToInt();
	num2.convertToInt();
	int max_lenth = (num1.digit > num2.digit) ? num1.digit : num2.digit;
	int min_lenth = (num1.digit < num2.digit) ? num1.digit : num2.digit;
	int *resultNum = new int[min_lenth + max_lenth];

	memset(resultNum, 0, 4 * (min_lenth + max_lenth));
	int i, j, k, z = min_lenth + max_lenth - 1;

	for (j = min_lenth - 1; j >= 0; j--)
	{
		for (k = z, i = max_lenth - 1; i >= 0; k--, i--)
		{
			resultNum[k] += (num1.digit > num2.digit) ? (num1.lnumint[i] * num2.lnumint[j]) : (num1.lnumint[j] * num2.lnumint[i]);
			if (resultNum[k] >= 10)
			{
				if (k != 0)
					resultNum[k - 1] += resultNum[k] / 10;
				resultNum[k] %= 10;
			}
		}
		//for(;k>=0;k--)
		//resultNum[k]=resultNum[k];
		z--;
	}
	LongNumber resultstr;
	resultstr.convertToChar(resultNum, min_lenth + max_lenth);
	return resultstr;

}

LongNumber operator/(LongNumber & num1, LongNumber & num2)
{
	num1.convertToInt();
	num2.convertToInt();

	int max_lenth,
		min_lenth,
		*dividend,
		*denominator;

	bool endoperator = false;

	int *resultNum, *tempDenominator,
		result_lenth;

	int i, j, count, z = 0, k = 0, min;

	if (num1.digit == num2.digit)
	{
		for (int i = 0; i<num1.digit; i++)
		{
			if (num1.lnumint[i] == num2.lnumint[i])
				continue;
			if (num1.lnumint[i]>num2.lnumint[i])
			{
				max_lenth = num1.digit;
				min_lenth = num2.digit;
				dividend = num1.lnumint;
				denominator = num2.lnumint;
				break;

			}

			if (num1.lnumint[i]<num2.lnumint[i])
			{
				endoperator = true;
				k = result_lenth = 1;
				resultNum = new int[result_lenth];
				resultNum[0] = 0;
				break;
			}
		}
	}
	else if (num1.digit > num2.digit)
	{
		max_lenth = num1.digit;
		min_lenth = num2.digit;
		dividend = num1.lnumint;
		denominator = num2.lnumint;

	}

	else if (num1.digit < num2.digit)
	{
		endoperator = true;
		k = result_lenth = 1;
		resultNum = new int[result_lenth];
		resultNum[0] = 0;
	}

	if (endoperator == false)
	{
		result_lenth = max_lenth - min_lenth + 1;
		resultNum = new int[result_lenth];
		tempDenominator = new int[min_lenth + 1];

		memset(resultNum, 0, 4 * (result_lenth));
		memset(tempDenominator, 0, 4 * (min_lenth + 1));
		min = min_lenth;
	}




	while (endoperator == false)
	{
		if (max_lenth<min)
			break;
		if (k == 0)
		{
			for (i = z, j = 0; i<min, j<min_lenth; i++, j++)
			{
				if (dividend[i]>denominator[j])
					break;
				if (dividend[i] == denominator[j])
					continue;
				if (dividend[i]<denominator[j])
				{
					min++;
					break;
				}
			}
		}

		for (count = 0;; count++)
		{
			// start zarb
			int x;
			for (int y = min_lenth - 1, x = min_lenth; y >= 0; x--, y--)
			{
				tempDenominator[x] += denominator[y] * count;
				if (tempDenominator[x] >= 10)
				{
					if (x != 0)
						tempDenominator[x - 1] = tempDenominator[x] / 10;
					tempDenominator[x] %= 10;
				}
			}
			//for(;x>=0;x--)
			//tempDenominator[x]=tempDenominator[x];
			//end zarb
			if (comp::compare(tempDenominator, dividend, min, z, min_lenth))
			{
				count--;
				break;
			}
			memset(tempDenominator, 0, 4 * (min_lenth + 1));
		}
		memset(tempDenominator, 0, 4 * (min_lenth + 1));

		for (int y = min_lenth - 1, x = min_lenth; y >= 0; x--, y--)
		{
			tempDenominator[x] += denominator[y] * count;
			if (tempDenominator[x] >= 10)
			{
				if (x != 0)
					tempDenominator[x - 1] = tempDenominator[x] / 10;
				tempDenominator[x] %= 10;
			}
		}

		for (i = min - 1, j = min_lenth; j >= 0; i--, j--)
		{
			if (i >= 0)
			{
				dividend[i] -= tempDenominator[j];
				if (dividend[i]<0)
				{
					if (i != 0)
						dividend[i - 1] -= 1;
					dividend[i] += 10;
				}
			}
		}
		min++;
		if (dividend[z] == 0)
			z++;
		resultNum[k] = count;
		k++;
		memset(tempDenominator, 0, 4 * (min_lenth + 1));
	}
	LongNumber resultstr;
	resultstr.convertToChar(resultNum, k);
	return resultstr;
}

bool operator >(LongNumber & num1, LongNumber & num2)
{
	num1.convertToInt();
	num2.convertToInt();

	if (num1.digit > num2.digit)
		return true;
	if (num1.digit < num2.digit)
		return false;
	if (num1.digit == num2.digit)
	{
		int i = 0;
		int p = 0;
		int n = 0;
		while (i>num1.digit)
		{
			if (num1.lnumint[i] > num2.lnumint[i])
			{
				p++;
			}
			else if (num1.lnumint[i] < num2.lnumint[i])
			{
				n++;
			}
			i++;
		}
		if (p<n)
			return true;
		return false;
	}
}
bool operator <(LongNumber & num1, LongNumber & num2)
{
	num1.convertToInt();
	num2.convertToInt();

	if (num1.digit> num2.digit)
		return true;
	if (num1.digit<num2.digit)
		return false;
	if (num1.digit == num2.digit)
	{
		int i = 0;
		int p = 0;
		int n = 0;
		while (i>num1.digit)
		{
			if (num1.lnumint[i] > num2.lnumint[i])
			{
				p++;
			}
			else if (num1.lnumint[i] < num2.lnumint[i])
			{
				n++;
			}
			i++;
		}
		if (p>n)
			return true;
		return false;
	}
}
bool operator ==(LongNumber & num1, LongNumber & num2)
{
	num1.convertToInt();
	num2.convertToInt();
	if (num1.digit == num2.digit)
	{
		int i = 0;
		int a = 0;
		while (i<num1.digit)
		{
			if (num1.lnumint[i] == num2.lnumint[i])
				a++;
			i++;
		}
		if (a == num1.digit)
			return true;
	}
	return false;
}


ostream & operator<<(ostream & os1, LongNumber & num)
{
	os1 << num.lnumstr;
	cout << endl;
	return os1;
}
istream & operator>>(istream & is1, LongNumber & num)
{
	//if (num.digit>0){ 
	//delete []num.lnumstr; 
	//num.digit = 0; }
	cout << "enter num";
	string temp;
	is1 >> temp;
	num.digit = temp.size();
	num.lnumstr = new char[num.digit];
	strcpy_s(num.lnumstr, num.digit,temp.c_str());

	return is1;
}