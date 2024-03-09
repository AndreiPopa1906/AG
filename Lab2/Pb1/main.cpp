#include <stdlib.h>
#include <stdio.h>
#include "NumberList.h"
int main()
{
	NumberList p;
	p.Init();
	for (int i = 6; i >= 1; i--)
		p.Add(i * 2 + 1);
	p.Sort();
	p.Print();
}