#include <iostream>
#include "Circuit.h"
#include "Dacia.h"
#include "Toyota.h"
#include "Mercedes.h"
#include "Ford.h"
#include "Mazda.h"
#include "Weather.h"

int main()
{
    Circuit c;
    c.SetLength(150);
    c.SetWeather(Weather::Rain);
    c.AddCar(new Dacia());
    c.AddCar(new Toyota());
    c.AddCar(new Mercedes());
    c.AddCar(new Ford());
    c.AddCar(new Mazda()); 
    c.Race();
    c.ShowFinalRanks();
    c.ShowWhoDidNotFinish(); 
    //c.Print();
    return 0;
}


