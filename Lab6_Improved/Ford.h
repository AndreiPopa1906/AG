#include "Car.h"
class Ford : public Car
{
	string name = "Ford";
	float fuel_capacity = 2500;
	float fuel_consumption = 13;
	float average_speed = 80;
	Weather weather = Weather::Rain;
public:
	float  get_fuel_capacity(); //in cm^3
	float get_fuel_consumption(); // in l/km
	float get_average_speed(); // in km/hour
	string get_name();
	void mod_fuel_capacity(int); //in cm^3
	void mod_fuel_consumption(int); // in l/km
	void mod_average_speed(int); // in km/hour
	Ford();
};
