#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Car.h"
#include"Circuit.h"
#include"Dacia.h"
#include"Toyota.h"
int main()
{
	Circuit circuit;
	circuit.setLength(10000);
	circuit.setWeather(Weather::RAIN);
	circuit.addCar(new Dacia());
	circuit.addCar(new Toyota());
	circuit.Race();
	circuit.showFinalResults(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	circuit.showNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
	circuit.Race();
	system("pause");
	return 0;
}