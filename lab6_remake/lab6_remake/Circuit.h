#pragma once
#include"Car.h"
#include"Weather.h"
#include"Dacia.h"
#include"Toyota.h"
class Circuit
{
	int v[5] = {0};//vector cu care retin pozitia pentru o masina.
	int length;
	Weather weather;
	int carCount;
	//int masina;
	Car *car[5];//array de 5 obiecte de tip Car

public:
	Circuit();
	void setLength(int length);
	void setWeather(Weather weather);
	void addCar(Car* carToAdd);
	void Race();
	void showFinalResults();
	void showNotFinish();
	float checkGas(Car* car);

};

