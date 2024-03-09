#include "Toyota.h"
#include "Weather.h"

Toyota::Toyota()
{
	name = "Toyota";
	mod_fuel_capacity(2300);
	mod_fuel_consumption(15);
	mod_average_speed(65);
	weather = Weather::Rain;
}

float Toyota::get_fuel_capacity() { return fuel_capacity; }; //in cm^3
float Toyota::get_fuel_consumption() { return fuel_consumption; }; // in l/km
float Toyota::get_average_speed() { return average_speed; }; // in km/hour
string Toyota::get_name() { return name; };
void Toyota::mod_fuel_capacity(int v) { fuel_capacity = v; }; //in cm^3
void Toyota::mod_fuel_consumption(int v) { fuel_consumption = v; }; // in l/km
void Toyota::mod_average_speed(int v) { average_speed = v; };
