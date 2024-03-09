#ifndef CAR_H
#define CAR_H

#include "Weather.h"
#include <string>
using namespace std;
class Car
{
public:
	float fuel_capacity = 0; //in cm^3
	float fuel_consumption = 0; // in l/km
	float average_speed = 0; // in km/hour
	string name;
	Weather weather;
};
#endif // CAR_H



