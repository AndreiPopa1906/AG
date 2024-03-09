#include "Number.h"
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <stdlib.h>

Number::Number(const char* value, int base)
{
	int len = strlen(value);
	this->s = new char[len + 1];
	size = len;

	// Copy the value into the string and set the base
	for (int i = 0; i < len; i++) 
	{
		s[i] = toupper(value[i]);
	}
	s[len] = NULL;
	this->base = base;
}

Number::Number(int value)
{
	int cont = 0, k = 0;
	int aux = value;
	do
	{
		aux /= 10;
		cont++;
	} while (aux);
	char* c = new char[cont + 1];
	itoa(value, c, 10);
	this->s = c;
	this->base = 10;
	this->size = cont;
}
/*Number::Number(const char* value)
{
	int len = strlen(value);
	s = new char[len + 1];
	size = len;

	// Copy the value into the string and set the base
	for (int i = 0; i < len; i++)
	{
		s[i] = toupper(value[i]);
	}
	s[len] = NULL;
	this->base = 10;
}*/

Number::~Number()
{
	if (s != nullptr) {
		delete[] s;
		s = nullptr;
	}
	size = 0;
	base = 10;
}

Number::Number(const Number& other)
{
    s = new char[other.size];
	for (int i = 0; i <= other.size - 1; i++)
	{
		this->s[i] = toupper(other.s[i]);
	}
	this->s[other.size] = NULL;
	this->size = other.size;
	this->base = other.base;
}

Number::Number(Number&& other) 
{
	std::swap(this->s, other.s);
	std::swap(this->base, other.base);
	std::swap(this->size, other.size);
}

Number& Number::operator=(const Number& other) 
{
    if (this == &other) {
        return *this;
    }
    delete[] this->s;
    this->s = new char[other.size];
    for (int i = 0; i < other.size; i++) 
        this->s[i] = other.s[i];
	this->base = other.base;
	this->size = other.size;
    return *this;
}
Number& Number::operator=(const char* value)
{
	int len = strlen(value);

	// Copy the value into the string and set the base
	
	s[len] = NULL;
	delete[] this->s;
	this->s = new char[len];
	for (int i = 0; i < len; i++)
	{
		s[i] = toupper(value[i]);
	}
	this->size = len;
	return *this;
}

Number& Number::operator=(int value)
{
	int aux = value, cont = 0;
	do
	{
		cont++;
		aux /= this->base;

	} while (aux);
	int len = cont;
	delete[] this->s;
	this->s = new char[len + 1];
	this->size = len;
	itoa(value, this->s, this->base);
	return *this;
}

Number& operator+(Number& n1, Number& n2)
{
	int base = std::max(n1.Number::GetBase(), n2.Number::GetBase());
	Number num1 = n1;
	Number num2 = n2;
	num1.SwitchBase(10);
	num2.SwitchBase(10);
	int MAX_SIZE = std::max(num1.Number::GetDigitsCount(), num2.Number::GetDigitsCount()) + 1;
	char* c = new char[MAX_SIZE];
	int nb1 = atoi(num1.s);
	int nb2 = atoi(num2.s);
	int sum = nb1 + nb2;
	itoa(sum, c, base);
	/*
	int i = num1.Number::GetDigitsCount() - 1, j = num2.Number::GetDigitsCount() - 1;
	int k = 0;
	int a, b, aux;
	int carry = 0, sum = 0;
	char r[1];
	while (i >= 0 || j >= 0 || carry)
	{
		if (i >= 0)
		{
			if (num1.s[i] >= '0' && num1.s[i] <= '9')
				a = num1.s[i] - '0';
			else
				a = num1.s[i] - 'A' + 10;
		}
		else a = 0;
		if (j >= 0)
		{
			if (num2.s[i] >= '0' && num2.s[i] <= '9')
				b = num2.s[i] - '0';
			else
				b = num2.s[i] - 'A' + 10;
		}
		else b = 0;
		sum = a + b + carry;
		carry = sum / base;
		sum = sum % base;
		//if (sum >= 0 && sum <= 9)
			//c[k++] = (char)(sum + '0');
		//else
			//c[k++] = (char)(sum - 10 + 'A');
		//c[k++] = sum + '0';
		itoa(sum, r,10);
		i--; j--;
	}*/
	//c[k++] = NULL;
	//strrev(c);
	Number *result = new Number(c, base);
	return *result;
}


Number& operator-(Number& n1, Number& n2) 
{
	int base = std::max(n1.GetBase(), n2.GetBase());
	Number num1 = n1;
	Number num2 = n2;
	num1.SwitchBase(base);
	num2.SwitchBase(base);
	//int base1 = n1.base;
	//int base2 = n2.base;
	int MAX_SIZE = std::max(num1.Number::GetDigitsCount(), num2.Number::GetDigitsCount()) + 1;
	char* c = new char[MAX_SIZE];
	int nb1 = atoi(num1.s);
	int nb2 = atoi(num2.s);
	int dif = abs(nb1 - nb2);
	itoa(dif, c, 10);
	/*int i = n1.size, j = n2.size;
	int k = 0;
	int a, b, aux = 0;
	int carry = 0, dif = 0;
	while (i >= 0 && j >= 0)
	{
		char r;
		if (n1.s[i] == 'A') a = 10;
		else if (n1.s[i] == 'B') a = 11;
		else if (n1.s[i] == 'C') a = 12;
		else if (n1.s[i] == 'D') a = 13;
		else if (n1.s[i] == 'E') a = 14;
		else if (n1.s[i] == 'F') a = 15;
		else a = n1.s[i] - '0';
		if (n2.s[j] == 'A') b = 10;
		else if (n2.s[j] == 'B') b = 11;
		else if (n2.s[j] == 'C') b = 12;
		else if (n2.s[j] == 'D') b = 13;
		else if (n2.s[j] == 'E') b = 14;
		else if (n2.s[j] == 'F') b = 15;
		else b = n2.s[j] - '0';
		a -= carry;
		if (a < b) a += 10, carry = 1;
		else carry = 0;
		dif = a - b;
		r = dif + '0';
		c[k++] = r;
		i--; j--;
	}
	while (i >= 0) c[k++] = n1.s[i--];
	while (j >= 0) c[k++] = n2.s[j--];
	while (c[k] == 0) { strcpy(c + k, c + k - 1); k--; }
	c[k++] = NULL;
	strrev(c);*/
	Number* result = new Number(c, base);
	//n1.SwitchBase(base1);
	//n2.SwitchBase(base2);
	return *result;
}


char Number::operator[](int index)
{
	return *(this->s + index);
}

bool Number::operator<(Number& other)
{
	int base1 = this->base;
	int base2 = other.base;
	this->SwitchBase(10);
	other.SwitchBase(10);
	if (strcmp(this->s, other.s) < 0)
	{
		this->SwitchBase(base1);
		other.SwitchBase(base2);
		return true;
	}
	this->SwitchBase(base1);
	other.SwitchBase(base2);
	return false;
}

bool Number::operator<=(Number& other)
{
	int base1 = this->base;
	int base2 = other.base;
	this->SwitchBase(10);
	other.SwitchBase(10);
	if (strcmp(this->s, other.s) <= 0)
	{
		this->SwitchBase(base1);
		other.SwitchBase(base2);
		return true;
	}
	this->SwitchBase(base1);
	other.SwitchBase(base2);
	return false;
}
bool Number::operator>(Number& other)
{
	int base1 = this->base;
	int base2 = other.base;
	this->SwitchBase(10);
	other.SwitchBase(10);
	if (strcmp(this->s, other.s) > 0)
	{
		this->SwitchBase(base1);
		other.SwitchBase(base2);
		return true;
	}
	this->SwitchBase(base1);
	other.SwitchBase(base2);
	return false;
}

bool Number::operator>=(Number& other)
{
	int base1 = this->base;
	int base2 = other.base;
	this->SwitchBase(10);
	other.SwitchBase(10);
	if (strcmp(this->s, other.s) >= 0)
	{
		this->SwitchBase(base1);
		other.SwitchBase(base2);
		return true;
	}
	this->SwitchBase(base1);
	other.SwitchBase(base2);
	return false;
}

bool Number::operator==(Number& other)
{
	int base1 = this->base;
	int base2 = other.base;
	this->SwitchBase(10);
	other.SwitchBase(10);
	if (strcmp(this->s, other.s) == 0)
	{
		this->SwitchBase(base1);
		other.SwitchBase(base2);
		return true;
	}
	this->SwitchBase(base1);
	other.SwitchBase(base2);
	return false;
}

bool Number::operator!=(Number& other)
{
	int base1 = this->base;
	int base2 = other.base;
	this->SwitchBase(10);
	other.SwitchBase(10);
	if (strcmp(this->s, other.s) != 0)
	{
		this->SwitchBase(base1);
		other.SwitchBase(base2);
		return true;
	}
	this->SwitchBase(base1);
	other.SwitchBase(base2);
	return false;
}

void Number::SwitchBase(int newBase) 
{
	// Convert to decimal
	int decimalValue = 0;
	for (int i = Number::GetDigitsCount() - 1, power = 1; i >= 0; i--, power *= newBase) {
		int digit = (s[i] >= '0' && s[i] <= '9') ? (s[i] - '0') : (s[i] - 'A' + 10);
		decimalValue += digit * power;
	}

	// Convert to new base
	int tempValue = decimalValue;
	int newLength = 0;
	while (tempValue != 0) {
		tempValue /= newBase;
		newLength++;
	}

	char* newString = new char[newLength + 1];
	newString[newLength] = '\0';

	for (int i = newLength - 1; i >= 0; i--) {
		int digit = decimalValue % newBase;
		newString[i] = (digit < 10) ? (digit + '0') : (digit - 10 + 'A');
		decimalValue /= newBase;
	}

	// Update object state
	//delete[] s;
	s = newString;
	base = newBase;
	size = newLength;
}


void Number::Print()
{
	for (int i = 0; i <= this->size - 1; i++)
		std::cout << s[i];
	std::cout << '\n';
}

int Number::GetDigitsCount()
{
	return this->size;
}

int Number::GetBase()
{
	return this->base;
}

void Number::operator--(int value)
{	
	int len = this->size;
	char* c = new char[len];
	for (int i = 0; i < len - 1; i++)
	{
		c[i] = this->s[i];
	}
	c[len - 1] = NULL;
	len--;
	int base = this->base;
	//Number* result = new Number(c);
	//Number::~Number();
	this->s = c;
	this->base = base;
	this->size = len;

}

void Number::operator--()
{
	int len = this->size;
	char* c = new char[len];
	for (int i = 1; i < len ; i++)
	{
		c[i - 1] = this->s[i];
	}
	c[len - 1] = NULL;
	len--;
	int base = this->base;
	//Number* result = new Number(c);
	//Number::~Number();
	this->s = c;
	this->base = base;
	this->size = len;
}

int CharToInt(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	else
		return c - 'A' + 10;
}
char IntToChar(int i)
{
	if (i >= 0 && i <= 9)
		return i + '0';
	else
		return i - 10 + 'A';
}


Number& operator+=(Number& n1, Number& n2)
{
	/*
	int maxSize = std::max(n1.size, n2.size) + 1; // add 1 to allow for carry
	char* result = new char[maxSize];

	int carry = 0;
	int i = n1.size - 1;
	int j = n2.size - 1;
	int k = maxSize - 1;

	while (i >= 0 || j >= 0)
	{
		int digit1 = (i >= 0) ? CharToInt(n1.s[i]) : 0;
		int digit2 = (j >= 0) ? CharToInt(n2.s[j]) : 0;
		int sum = digit1 + digit2 + carry;
		carry = (sum >= n1.base) ? 1 : 0;
		result[k] = IntToChar(sum % n1.base);
		i--;
		j--;
		k--;
	}

	if (carry > 0)
	{
		result[0] = IntToChar(carry);
		n1.size = maxSize;
		delete[] n1.s;
		n1.s = result;
	}
	else
	{
		n1.size = maxSize - 1;
		delete[] n1.s;
		n1.s = new char[n1.size];
		for (int i = 0; i < n1.size; i++)
		{
			n1.s[i] = result[i + 1];
		}
	}
	delete[] result;
	return n1;*/

	int base2 = n2.base;
	n2.SwitchBase(n1.base);

	int maxSize = std::max(n1.size, n2.size) + 1; // add 1 to allow for carry
	char* result = new char[maxSize];


	int carry = 0;
	int i = n1.size - 1;
	int j = n2.size - 1;
	int k = maxSize - 1;

	while (i >= 0 || j >= 0)
	{
		int digit1 = (i >= 0) ? CharToInt(n1.s[i]) : 0;
		int digit2 = (j >= 0) ? CharToInt(n2.s[j]) : 0;
		int sum = digit1 + digit2 + carry;
		carry = (sum >= n1.base) ? 1 : 0;
		result[k] = IntToChar(sum % n1.base);
		i--;
		j--;
		k--;
	}

	if (carry > 0)
	{
		result[0] = IntToChar(carry);
		n1.size = maxSize;
		delete[] n1.s;
		n1.s = result;
	}
	else
	{
		n1.size = maxSize - 1;
		delete[] n1.s;
		n1.s = new char[n1.size];
		for (int i = 0; i < n1.size; i++)
		{
			n1.s[i] = result[i + 1];
		}
	}
	n2.SwitchBase(base2);
	//delete[] result;
	return n1;
}

/*Number& operator-=(Number& n1, Number& n2)
{
	/*int i = n1.size, j = n2.size;
	int k = 0;
	int a, b, aux = 0;
	int carry = 0, dif = 0;
	while (i >= 0 && j >= 0)
	{
		char r;
		if (n1.s[i] == 'A') a = 10;
		else if (n1.s[i] == 'B') a = 11;
		else if (n1.s[i] == 'C') a = 12;
		else if (n1.s[i] == 'D') a = 13;
		else if (n1.s[i] == 'E') a = 14;
		else if (n1.s[i] == 'F') a = 15;
		else a = n1.s[i] - '0';
		if (n2.s[j] == 'A') b = 10;
		else if (n2.s[j] == 'B') b = 11;
		else if (n2.s[j] == 'C') b = 12;
		else if (n2.s[j] == 'D') b = 13;
		else if (n2.s[j] == 'E') b = 14;
		else if (n2.s[j] == 'F') b = 15;
		else b = n2.s[j] - '0';
		a -= carry;
		if (a < b) a += 10, carry = 1;
		else carry = 0;
		dif = a - b;
		r = dif + '0';
		c[k++] = r;
		i--; j--;
	}
	while (i >= 0) c[k++] = n1.s[i--];
	while (j >= 0) c[k++] = n2.s[j--];
	while (c[k] == 0) { strcpy(c + k, c + k - 1); k--; }
	c[k++] = NULL;
	strrev(c);
	//-------------------------------------
	int maxSize = std::max(n1.size, n2.size) + 1; // add 1 to allow for carry
	char* result = new char[maxSize];

	int carry = 0;
	int i = n1.size - 1;
	int j = n2.size - 1;
	int k = maxSize - 1;

	while (i >= 0 || j >= 0)
	{
		int digit1 = (i >= 0) ? CharToInt(n1.s[i]) : 0;
		int digit2 = (j >= 0) ? CharToInt(n2.s[j]) : 0;
		int dif = digit1 - digit2 - carry;
		carry = (dif >= 0) ? 1 : 0;
		result[k] = IntToChar(dif % n1.base);
		i--;
		j--;
		k--;
	}

	n1.size = maxSize - 1;
	delete[] n1.s;
	n1.s = new char[n1.size];
	for (int i = 0; i < n1.size; i++)
	{
		n1.s[i] = result[i + 1];
	}
	delete[] result;
	return n1;
}*/



