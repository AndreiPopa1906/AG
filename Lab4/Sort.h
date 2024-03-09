#include <initializer_list>
#include <algorithm>
class Sort
{
	// add data members
	int* a;
	int n;
	void QuickSortHelper(int low, int high, bool ascendent);
	int Partition(int low, int high, bool ascendent);
public:
	Sort(int, int, int);
	explicit Sort(int* , int);
	explicit Sort(int, ...);
	Sort(char*);
	explicit Sort(std::initializer_list<int> init_list);
	void InsertSort(bool ascendent = false);
	void QuickSort(bool ascendent = false);
	void BubbleSort(bool ascendent = false);
	void Print();
	int  GetElementsCount();
	int  GetElementFromIndex(int index);
	//~Sort();
};
