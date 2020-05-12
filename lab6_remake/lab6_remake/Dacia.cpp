#include "Dacia.h"



Dacia::Dacia()
{
	this->fuelCapacity = 90;
	this->fuelConsumption = 7;
	this->averageSpeed[0] = 50;
	this->averageSpeed[1] = 60;
	this->averageSpeed[2] = 100;
}

int Dacia::getFuelCapacity()
{
	return this->fuelCapacity;
}

int Dacia::getFuelConsumption()
{
	return this->fuelConsumption;
}

float Dacia::getAverageSpeed(Weather weather)
{
	if (weather == Weather::RAIN)
		return this->averageSpeed[0];
	if (weather == Weather::SNOWY)
		return this->averageSpeed[1];
	if (weather == Weather::SNOWY)
		return this->averageSpeed[2];

}