#include "Sort.h"
#include <initializer_list>
#include <algorithm>
#include <iostream>
int main()
{
	int n=3, min=29, max=39;
	char s[] = "134,2234,323123,432,534";
	int v[5] = {1,2,3,4,5};
	for (int i = 0; i <= 4; i++) v[i] = 2 * i;
	Sort v1(n, min, max);
	v1.QuickSort(true);
	v1.Print();
	std::cout << '\n';
	Sort v2({ 1, 2, 3, 4, 5, 6 });
	v2.QuickSort(true);
	v2.Print();
	std::cout << '\n';
	Sort v3(v,5);
	v3.QuickSort(true);
	v3.Print();
	std::cout << '\n';
	Sort v4(3, 1, 2, 3); 
	v4.QuickSort(true);
	v4.Print();
	std::cout << '\n';
	Sort v5(s);
	v5.QuickSort(true);
	v5.Print();
	std::cout << '\n';
}