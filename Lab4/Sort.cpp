#include "Sort.h"
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <stdarg.h>
#include <cstring>
#include <iostream>
#include <initializer_list>
#include <algorithm>
Sort::Sort(int n, int min, int max) // cerinta 1
{
    srand(time(NULL));

    this->n = n;
    this->a = new int[this->n];

    for (int i = 0; i < n; i++)
        this->a[i] = rand() % (max - min) + min;
        
}
Sort::Sort(int x[], int n) // cerinta 3
{
    this->n = n;
    a = x;
}

Sort::Sort(char* s)//cerinta 5
{
    char* s1 = new char[strlen(s) + 1];
    strcpy(s1, s);
    int cont = 0;
    char* token = strtok(s1, ",");
    while (token != NULL) 
    {
         cont++;
         token = strtok(NULL, ",");
    }
    this->n = cont;
    a = new int[n];
    char* p;
    int k = 0, i = 0;
    int nr = 0;
    p = strtok(s, ",");
    while (p) 
    {
        nr = 0;
        k = 0;
        while (k < strlen(p)) 
        {
            nr = nr * 10 + (p[k] - '0');
            k++;
        }
        a[i] = nr;
        i++;
        p = strtok(NULL, ",");
    }
}
Sort::Sort(int count, ...) // cerinta 4
{
    this->n = count;
    a = new int[count];
    va_list list;
    va_start(list, count);
    for (int i = 0; i < count; i++)
    {
        this->a[i] = va_arg(list, int);
    }
    va_end(list);
}
Sort::Sort(std::initializer_list<int> init_list) // cerinta 2
{
    a = new int[init_list.size()]; 
    n = init_list.size();
    std::copy(init_list.begin(), init_list.end(), a);
}
void Sort::Print()
{
    for (int i = 0; i < this->n; i++)
        printf("%d ", this->a[i]);
}
void Sort::InsertSort(bool ascendent)
{
    int n = Sort::GetElementsCount();
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int key = a[i];
        while (j >= 0 && ((ascendent && a[j] > key) || (!ascendent && a[j] < key))) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
void Sort::QuickSortHelper(int low, int high, bool ascendent)
{
    if (low < high)
    {
        int pivot = Sort::Partition(low, high, ascendent);
        Sort::QuickSortHelper(low, pivot - 1, ascendent);
        Sort::QuickSortHelper(pivot + 1, high, ascendent);
    }
}

void Sort::QuickSort(bool ascendent)
{
    int n = Sort::GetElementsCount();
    Sort::QuickSortHelper(0, n - 1, ascendent);
}

int Sort::Partition(int low, int high, bool ascendent)
{
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (ascendent ? (a[j] <= pivot) : (a[j] >= pivot))
        {
            i++;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[high]);
    return i + 1;
}

void Sort::BubbleSort(bool ascendent)
{
    int n = Sort::GetElementsCount();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (ascendent ? (a[j] > a[j + 1]) : (a[j] < a[j + 1]))
                std::swap(a[j], a[j + 1]);
}
int  Sort::GetElementsCount()
{
    return this->n;
}
int Sort::GetElementFromIndex(int index)
{
    return this->a[index];
}
/*Sort::~Sort()
{
    this->n = 0;
    delete this->a;
}*/



