#include "Toyota.h"



Toyota::Toyota()
{
	this->fuelCapacity = 120;
	this->fuelConsumption = 9;
	this->averageSpeed[0] = 120;
	this->averageSpeed[1] = 100;
	this->averageSpeed[2] = 80;
}

int Toyota::getFuelCapacity()
{
	return this->fuelCapacity;
}

int Toyota::getFuelConsumption()
{
	return this->fuelConsumption;
}

float Toyota::getAverageSpeed(Weather weather)
{
	if (weather == Weather::RAIN)
		return this->averageSpeed[0];
	if (weather == Weather::SNOWY)
		return this->averageSpeed[1];
	if (weather == Weather::SNOWY)
		return this->averageSpeed[2];

}