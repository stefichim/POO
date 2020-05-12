#pragma once
#include"Car.h"
#include"Weather.h"
#include"Dacia.h"
class Circuit
{
	int length;
	Weather weather;
	//int masina;
	Car *car[5];//array de 5 obiecte de tip Car

public:
	void setLength(int length);
	void setWeather(Weather weather);
	void addCar(Car* carToAdd);
	void Race();
	void showFinalResults();
	void showNotFinish();
	
};

