#pragma once
#include"Car.h"
#include"Weather.h"
class Toyota : public Car
{
public:
	Toyota();
	int getFuelCapacity();
	int getFuelConsumption();
	float getAverageSpeed(Weather weather);
};

