#include "Mercedes.h"
#include "Weather.h"

Mercedes::Mercedes()
{
	name = "Mercedes";
	mod_fuel_capacity(1900);
	mod_fuel_consumption(18);
	mod_average_speed(90);
	weather = Weather::Rain;
}

float Mercedes::get_fuel_capacity() { return fuel_capacity; }; //in cm^3
float Mercedes::get_fuel_consumption() { return fuel_consumption; }; // in l/km
float Mercedes::get_average_speed() { return average_speed; }; // in km/hour
string Mercedes::get_name() { return name; };
void Mercedes::mod_fuel_capacity(int v) { fuel_capacity = v; }; //in cm^3
void Mercedes::mod_fuel_consumption(int v) { fuel_consumption = v; }; // in l/km
void Mercedes::mod_average_speed(int v) { average_speed = v; };
