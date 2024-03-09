#include "Dacia.h"
#include "Weather.h"

Dacia::Dacia()
{
	name = "Dacia";
	mod_fuel_capacity(2000);
	mod_fuel_consumption(11);
	mod_average_speed(70);
	weather = Weather::Rain;
}

float Dacia::get_fuel_capacity() { return fuel_capacity; }; //in cm^3
float Dacia::get_fuel_consumption() { return fuel_consumption; }; // in l/km
float Dacia::get_average_speed() { return average_speed; }; // in km/hour
string Dacia::get_name() { return name; };
void Dacia::mod_fuel_capacity(int v) { fuel_capacity = v; }; //in cm^3
void Dacia::mod_fuel_consumption(int v) { fuel_consumption = v; }; // in l/km
void Dacia::mod_average_speed(int v) { average_speed = v; };



