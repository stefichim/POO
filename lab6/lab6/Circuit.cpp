#include "Circuit.h"
#include"Weather.h"
#include"Dacia.h"

void Circuit::setLength(int length)
{
	this->length = length;
}

void Circuit::setWeather(Weather weather)
{
	if (weather == Weather::RAIN)
		this->weather = Weather::RAIN;
	if (weather == Weather::SUNNY)
		this->weather = Weather::SUNNY;
	if (weather == Weather::SNOWY)
		this->weather = Weather::SNOWY;
}

//void Circuit::setCar(int masina)
//{
//	this->masina = masina;
//}

void Circuit::addCar(Car* carToAdd)
{
	for (int i = 0; i < 5; i++) {
		this->car[i] = carToAdd;
	}
}

void Circuit::Race()
{
	//deci mai intaii ar treb sa calculezi cat timp iti ia sa parcurgi distanta d cu viteza avgSpeed
	//time = distanta / viteza;

	//pentru fiecare masina trebuie sa calculez timpul care imi trebuie sa parcurg distanta de 100 km cu viteza avgSpeed pe RAIN


}