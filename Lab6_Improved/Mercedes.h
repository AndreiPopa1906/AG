#include "Car.h"
class Mercedes : public Car
{
	string name = "Mercedes";
	float fuel_capacity = 1900;
	float fuel_consumption = 18;
	float average_speed = 90;
	Weather weather = Weather::Rain;
public:
	float  get_fuel_capacity(); //in cm^3
	float get_fuel_consumption(); // in l/km
	float get_average_speed(); // in km/hour
	string get_name();
	void mod_fuel_capacity(int); //in cm^3
	void mod_fuel_consumption(int); // in l/km
	void mod_average_speed(int); // in km/hour
	Mercedes();
};
