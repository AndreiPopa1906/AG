#include "Ford.h"
#include "Weather.h"

Ford::Ford()
{
	name = "Ford";
	mod_fuel_capacity(2500);
	mod_fuel_consumption(13);
	mod_average_speed(80);
	weather = Weather::Rain;
}

float Ford::get_fuel_capacity() { return fuel_capacity; }; //in cm^3
float Ford::get_fuel_consumption() { return fuel_consumption; }; // in l/km
float Ford::get_average_speed() { return average_speed; }; // in km/hour
string Ford::get_name() { return name; };
void Ford::mod_fuel_capacity(int v) { fuel_capacity = v; }; //in cm^3
void Ford::mod_fuel_consumption(int v) { fuel_consumption = v; }; // in l/km
void Ford::mod_average_speed(int v) { average_speed = v; };


