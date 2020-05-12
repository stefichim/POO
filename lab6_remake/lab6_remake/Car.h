#pragma once
#include"Weather.h"
class Car
{
protected:
	int fuelCapacity, fuelConsumption;
	float averageSpeed[3];
public:
	virtual int getFuelCapacity() = 0;//abstract class
	virtual int getFuelConsumption() = 0;
	virtual float getAverageSpeed(Weather weather) = 0;
};

