#include "Math.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <cstdlib>
#define LGMAX 10000
int Math::Add(int x, int y)
{
	return x + y;
}
int Math::Add(int x, int y, int z)
{
	return x + y + z;
}
int Math::Add(double x, double y)
{
	return x + y;
}
int Math::Add(double x, double y, double z)
{
	return x + y + z;
}
int Math::Mul(int x, int y)
{
	return x * y;
}
int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}
int Math::Mul(double x, double y)
{
	return x * y;
}
int Math::Mul(double x, double y, double z)
{
	return x * y * z;
}
int Math::Add(int count, ...)
{
	va_list list;
	int sum = 0;
	int i;
	va_start(list, count);
	for (i = 0; i < count; i++) {
		sum += va_arg(list, int);
	}
	va_end(list);
	return sum;
}
char* Math::Add(const char* x, const char* y)
{
	if (x == nullptr || y == nullptr) return nullptr;
	char c[LGMAX] = {};
	int i = strlen(x) - 1, j = strlen(y) -1;
	int k = 0;
	int a, b, aux;
	int carry = 0, sum = 0;
	while (i >= 0 && j >= 0)
	{
		char r;
		a = x[i] - '0';
		b = y[j] - '0';
		sum = a + b;
		aux = sum / 10;
		sum = sum % 10 + carry;
		carry = aux;
		r = sum + '0';
		c[k++] = r;
		i--; j--;
	}
	while (i >= 0) c[k++] = x[i--];
	while (j >= 0) c[k++] = y[j--];
	strrev(c);
	return c;
}
