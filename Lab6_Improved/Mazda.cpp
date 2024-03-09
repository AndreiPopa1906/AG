#include "Mazda.h"
#include "Weather.h"

Mazda::Mazda()
{
	name = "Mazda";
	mod_fuel_capacity(1890);
	mod_fuel_consumption(15);
	mod_average_speed(65);
	weather = Weather::Rain;
}

float Mazda::get_fuel_capacity() { return fuel_capacity; }; //in cm^3
float Mazda::get_fuel_consumption() { return fuel_consumption; }; // in l/km
float Mazda::get_average_speed() { return average_speed; }; // in km/hour
string Mazda::get_name() { return name; };
void Mazda::mod_fuel_capacity(int v) { fuel_capacity = v; }; //in cm^3
void Mazda::mod_fuel_consumption(int v) { fuel_consumption = v; }; // in l/km
void Mazda::mod_average_speed(int v) { average_speed = v; };

