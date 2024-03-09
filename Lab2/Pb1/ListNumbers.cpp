#include "NumberList.h"
#include <stdio.h>
void NumberList::Init()
{
	this->count = 0;
}
bool NumberList::Add(int x)
{
	if (this->count >= 10) return false;
	else
	{
		this->numbers[this->count] = x;
		this->count++;
	}
}
void NumberList::Sort()
{
	int aux;
	int limit = this->count;
	for (int i = 0; i < limit - 1; i++)
		for (int j = i + 1; j < limit; j++)
			if (this->numbers[i] > this->numbers[j])
			{
				aux = this->numbers[i];
				this->numbers[i] = this->numbers[j];
				this->numbers[j] = aux;
			}
}
void NumberList::Print()
{
	for (int i = 0; i < this->count; i++)
		printf("%d ", this->numbers[i]);
}


