class Number
{   
	// add data members
	char* s = nullptr;
	int size = 0;
	int base = 10;

public:
	Number(const char* value, int base);
	Number(int value);
	//Number(const char* value);
	// where base is between 2 and 16   
	~Number();
	// add operators and copy/move constructor 
	Number(const Number& other); // copy constructor
	Number(Number&& other); // move constructor
	void SwitchBase(int newBase);
	Number& operator=(const Number& other);
	Number& operator=(const char* value);
	Number& operator=(int value);
	bool operator<(Number& other);
	bool operator<=(Number& other);
	bool operator>(Number& other);
	bool operator>=(Number& other);
	bool operator==(Number& other);
	bool operator!=(Number& other);
	friend Number& operator+(Number& n1, Number& n2);
	friend Number& operator-(Number& n1, Number& n2);
	void operator--(int value);
	void operator--();;
	char operator[](int index);
	friend Number& operator+=(Number& n1, Number& n2);
	//friend 	Number& operator-=(Number& n1, Number& n2);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number   
	int  GetBase(); // returns the current base
};