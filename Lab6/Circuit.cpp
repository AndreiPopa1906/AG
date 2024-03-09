#pragma warning( push )
#pragma warning( disable : 6386 )
//start programe
#include "Circuit.h"
#include <iostream>
using namespace std;

void Circuit::Set_specs_regarding_weather(int value)
{
    if(value == 0)
        for (int i = 0; i < index; i++)
        {
            v[i]->fuel_consumption += v[i]->fuel_consumption / 5; //rises with 20%
            v[i]->average_speed -= v[i]->average_speed / 10; // decreases with 10%
        }
    else if(value == 2)
        for (int i = 0; i < index; i++)
        {
            v[i]->fuel_consumption += v[i]->fuel_consumption / 3; //rises with 20%
            v[i]->average_speed -= v[i]->average_speed / 5; // decreases with 10%
        }

}
bool Circuit::Finished(Car* x)
{
    float dist = x->fuel_capacity / x->fuel_consumption;
    return (dist > length);
}

Circuit::Circuit()
{
    allocated = 5;
	v = new Car * [allocated];
    weather = Weather::Sunny;
	index = 0;
	length = 150;
}
void Circuit::SetLength(int value)
{
	this->length = value;
}
void Circuit::SetWeather(Weather weather)
{
	this->weather = weather;
}
void Circuit::AddCar(Car* car)
{
    Car* x = car;
    x->weather = weather;
    if (allocated == index)
    {
        allocated = allocated + grow;
        Car** aux = new Car * [allocated];
        for (int i = 0; i < index; i++)
            aux[i] = v[i];
        delete[] v; // delete previously allocated memory
        v = aux;
    }
    v[index++] = x;
}

void Circuit::Race()
{
    int value = static_cast<int> (weather);
    Set_specs_regarding_weather(value);
    Car* aux;
    Car** a = new Car * [allocated];
    for (int i = 0; i < index; i++)
        a[i] = v[i];
    cout << endl;
    for (int i = 0; i < index - 1; i++)
        for (int j = i + 1; j < index; j++)
            if (a[i]->average_speed < a[j]->average_speed)
            {
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
    for (int i = 0; i < index; i++)
        cout << a[i]->name << ' ';
    cout << endl;
    delete[] v; // delete previously allocated memory
    v = a;
}

void Circuit::ShowFinalRanks()
{
	cout << "Clasamentul masinilor care au termonat cursa este: ";
	for (int i = 0; i < index; i++)
		if (Finished(v[i]) == 1)
			cout << v[i]->name << ' ';
	cout << '\n';
}
void Circuit::ShowWhoDidNotFinish()
{
	cout << "Masinile care nu au terminat cursa sunt: ";
	for (int i = 0; i < index; i++)
		if (Finished(v[i]) == 0)
			cout << v[i]->name << ' ';
	cout << '\n';
}

void Circuit::Print()
{
	for (int i = 0; i < index; i++)
			cout << v[i]->name << ' ';
}
Circuit::~Circuit()
{
    delete[] v;
}
//end programe
#pragma warning( push )