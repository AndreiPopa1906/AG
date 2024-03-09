#ifndef CAR_H
#define CAR_H

#include "Weather.h"
#include <string>
using namespace std;
class Car
{
public:
	virtual float  get_fuel_capacity() = 0; //in cm^3
	float virtual get_fuel_consumption() = 0; // in l/km
	float virtual get_average_speed() = 0; // in km/hour
	string virtual get_name() = 0;
	void virtual mod_fuel_capacity(int) = 0; //in cm^3
	void virtual mod_fuel_consumption(int) = 0; // in l/km
	void virtual mod_average_speed(int) = 0; // in km/hour
	Weather weather;
};
#endif // CAR_H



