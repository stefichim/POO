#pragma once
#include"Car.h"
#include"Weather.h"
class Dacia : public Car
{
public:
	Dacia();
	int getFuelCapacity();
	int getFuelConsumption();
	float getAverageSpeed(Weather weather);
};

