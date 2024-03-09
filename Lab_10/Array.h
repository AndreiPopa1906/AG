#pragma once
#include <exception>

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

template <class T>
class MyComparator : public Compare {
public:
	int CompareElements(void* e1, void* e2) override {
		// Compare two elements of type T
		T* t1 = static_cast<T*>(e1);
		T* t2 = static_cast<T*>(e2);
		if (*t1 < *t2) return -1;
		if (*t1 > *t2) return 1;
		return 0;
	}
};


template<class T>
class ArrayIterator
{
private:
	int Current;
	T* Value;

public:
	ArrayIterator() : Current(0), Value(nullptr) {}
	ArrayIterator(const int index) : Current(index), Value(nullptr) {}

	ArrayIterator& operator++()
	{
		Current++;
		return *this;
	}

	ArrayIterator& operator--()
	{
		Current--;
		return *this;
	}
	bool operator=(ArrayIterator<T>& other)
	{
		Current = other.Current;
		Value = other.Value;
		return true;
	}

	bool operator==(ArrayIterator<T>& other)
	{
		return this->Current == other.Current;
	}

	bool operator!=(ArrayIterator<T>& other)
	{
		return !(*this == other);
	}

	T& GetElement()
	{
		if (Value != nullptr)
			return Value[Current];
		return nullptr;
	}

};


template<class T>
class Array
{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista
	void resize()
	{
		if (Capacity == 0)
		{
			Capacity = 10;
			Size = 0;
		}
		if (Size >= Capacity)
		{
			T** newArray = new T * [Capacity * 2]; 
			Capacity *= 2;
			memcpy(newArray, List, sizeof(T*) * Size); 
			delete[] List; 
			List = newArray; 
		}
	}

public:
	Array()// Lista nu e alocata, Capacity si Size = 0
	{
		Capacity = 0;
		Size = 0;
		List = new T * [Capacity]();
	}
	~Array()// destructor
	{
		for (int i = 0; i < Size; i++)
			delete List[i];
		Capacity = 0;
		Size = 0;
	}
	Array(int capacity) // Lista e alocata cu 'capacity' elemente
	{
		Capacity = capacity;
		Size = 0;
		List = new T * [capacity];
	}
	Array(const Array<T>& otherArray)  // constructor de copiere
	{
		Size = otherArray.Size;
		Capacity = otherArray.Capacity;
		delete[] List;
		List = new T * [Capacity];
		for (int i = 0; i < Size; i++)
			List[i] = new (T*)(otherArray.List[i]);
	}

	Array<T>& operator=(const Array<T>& otherArray)
	{
		if (this != &otherArray)
		{
			Size = otherArray.Size;
			Capacity = otherArray.Capacity;
			delete[] List;
			List = new T * [Capacity];
			memcpy(List, otherArray.List, sizeof(T*) * Size);
		}
		return *this;
	}
	bool operator==(const Array<T>& otherArray)
	{
		if (Size != otherArray.Size) return 0;
		for (int i = 0; i < Size; i++)
			if (List[i] != otherArray.List[i]) return 0;
		return 1;
	}

	T& operator[](int index)
	{
		if (index < 0 || index >= Size)
		{
			throw std::out_of_range("Index out of range");
		}
		return (T&)(List[index]);
		//return *(List[index]);
	}

	const Array<T>& operator+=(const T& newElem)
	{
		

		Size++;
		resize();
		List[Size - 1] = new T(newElem);

		/*Array object;
		memcpy(object.List, List, sizeof(T*) * Size);
		Size++;
		object[Size - 1] = newElem;
		memcpy(List, object.List, sizeof(T*) * Size);*/
		return *this;
	}

	const Array<T>& Insert(int index, const T& newElem)
	{
		if (index < 0 || index > Size)
			throw std::out_of_range("Index out of range!");

		resize();

		Array<T> tmp(Size + 1);
		std::memcpy(tmp.List, List, sizeof(T*) * index);
		std::memcpy(tmp.List + index + 1, List + index, sizeof(T*) * (Size - index));
		std::memcpy(tmp.List + index, &newElem, sizeof(T*));


		Size += 1;
		std::swap(List, tmp.List);
		return *this;
	}

	const Array<T>& Insert(int index, const Array<T>& otherArray)
	{
		if (index < 0 || index > Size)
			throw std::out_of_range("Index out of range!");

		resize();

		Array<T> tmp(Size + otherArray.Size);
		std::memcpy(tmp.List, List, sizeof(T*) * index);
		std::memcpy(tmp.List + index + otherArray.Size, List + index, sizeof(T*) * (Size - index));
		std::memcpy(tmp.List + index, otherArray.List, sizeof(T*) * otherArray.Size);

		Size += otherArray.Size;
		std::swap(List, tmp.List);

		return *this;
	}


	const Array<T>& Delete(int index) {
		if (index < 0 || index >= Size) {
			throw std::out_of_range("Index out of range!");
		}
		Size--;
		memmove(&List[index], &List[index + 1], sizeof(T*) * (Size - index));
		return *this;
	}

	void Sort() // sorteaza folosind comparatia intre elementele din T
	{
		for (int i = 0; i < Size - 1; i++)
			for (int j = i + 1; j < Size; j++)
				if (List[i] > List[j])
				{
					T* auxElem = List[i];
					List[i] = List[j];
					List[j] = auxElem;
				}
	}
	void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
	{
		for (int i = 0; i < Size - 1; i++)
			for (int j = i + 1; j < Size; j++)
				if (compare(List[i], List[j]) == 1)
				{
					T* auxElem = List[i];
					List[i] = List[j];
					List[j] = auxElem;
				}
	}
	void Sort(Compare* comparator) // sorteaza folosind un obiect de comparatie
	{

		for (int i = 0; i < Size - 1; i++)
			for (int j = i + 1; j < Size; j++)
				if (comparator->CompareElements(&List[i], &List[j]) > 0)
				{
					T* auxElem = List[i];
					List[i] = List[j];
					List[j] = auxElem;
				}
	}
	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista 
	int BinarySearch(const T& elem)// cauta un element folosind binary search in Array
	{
		int left = 0;
		int right = Size - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (static_cast<T*>(List[mid]) == elem) {
				return mid;
			}
			else if (static_cast<T*>(List[mid]) < elem) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		return -1;
	}
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind binary search si o functie de comparatie
	{
		int left = 0;
		int right = Size - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (compare(List[mid], elem) == 0) {
				return mid;
			}
			else if (compare(List[mid], elem) < 0) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		return -1;
	}
	int BinarySearch(const T& elem, Compare* comparator)//  cauta un element folosind binary search si un comparator
	{
		int left = 0;
		int right = Size - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (comparator->CompareElements(&List[mid], &elem) == 0) {
				return mid;
			}
			else if (comparator->CompareElements(&List[mid], &elem) < 0) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		return -1;
	}
	int Find(const T& elem) // cauta un element in 
	{
		for (int i = 0; i < Size; i++)
			if (elem == List[i]) return i;
		return -1;
	}
	int Find(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind o functie de comparatie
	{
		for (int i = 0; i < Size; i++)
			if (compare(List[i], elem) == 0) return i;
		return -1;
	}
	int Find(const T& elem, Compare* comparator)//  cauta un element folosind un comparator
	{
		for (int i = 0; i < Size; i++)
			if (comparator->CompareElements(&List[i], &elem) == 0) return i;
		return -1;
	}
	int GetSize()
	{
		return Size;
	}
	int GetCapacity()
	{
		return Capacity;
	}
	ArrayIterator<T> GetBeginIterator()
	{
		return ArrayIterator<T>(0);
	}
	ArrayIterator<T> GetEndIterator()
	{
		return ArrayIterator<T>(Size);
	}
};



