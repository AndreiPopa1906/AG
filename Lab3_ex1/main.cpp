#include "Math.h"
#include <stdio.h>
#include <stdarg.h>
#define LGMAX 1000
int main()
{
	int n = 5;
	printf("Exemplul 1: %d \n", Math::Add(1,2));
	printf("Exemplul 2: %d \n", Math::Add(1,2,3));
	printf("Exemplul 3: %lf \n", Math::Add(1.234,2.445));
	printf("Exemplul 4: %lf \n", Math::Add(1.33455,2.455,5.33445));
	printf("Exemplul 5: %d \n", Math::Mul(5,4));
	printf("Exemplul 6: %d \n", Math::Mul(5,4,7));
	printf("Exemplul 7: %lf \n", Math::Mul(5.445,4.2223));
	printf("Exemplul 8: %lf \n", Math::Mul(5.445,4.5667,6.334));
	printf("Exemplul 9: %d \n", Math::Add(n, 1, 2, 3, 4, 5));
	char* p = new char[LGMAX + 100];
	p = Math::Add("1256", "34890");
	printf("Exemplul 10: %s \n", p);

}