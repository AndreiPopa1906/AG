#include "Car.h"
#include "Weather.h"
class Circuit
{
private:
public:
	int length = 135;
	Car** v = {};
	int index = 0;
	int allocated;
	int grow = 10;
	//void* p = nullptr;
	Weather weather = Weather::Sunny;
	Circuit();
	bool Finished(Car*);
	void Set_specs_regarding_weather(int value);
	void SetLength(int);
	void SetWeather(Weather);
	void AddCar(Car*);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	void Print();
	~Circuit();
};
