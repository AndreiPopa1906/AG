#include "Car.h"
#include "Weather.h"
class Toyota : public Car
{
	string name = "Toyota";
	float fuel_capacity = 2300;
	float fuel_consumption = 15;
	float average_speed = 65;
	Weather weather = Weather::Rain;
public:
	float  get_fuel_capacity(); //in cm^3
	float get_fuel_consumption(); // in l/km
	float get_average_speed(); // in km/hour
	string get_name();
	void mod_fuel_capacity(int); //in cm^3
	void mod_fuel_consumption(int); // in l/km
	void mod_average_speed(int); // in km/hour
	Toyota();
};