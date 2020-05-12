#include "Circuit.h"
#include"Weather.h"
#include"Dacia.h"
#include<iostream>
#include"Toyota.h"

Circuit::Circuit()
{
	carCount = 0;
}
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

	this->car[carCount] = carToAdd; 
	carCount++;
}

float Circuit::checkGas(Car* car)
{
	float numarator, autonomy=0;
	numarator = car->getFuelCapacity() * 100;
	autonomy = numarator / car->getFuelConsumption();
	return autonomy;
	//functie prin care am calculat autonomia unei masini care nu tine cont de starea vremii?
}

void Circuit::showNotFinish()
{
	for (int i = 0; i < carCount; i++) {
		if (checkGas(car[i]) > length)
			std::cout << "Masina " << car[i] << " nu a reusit sa termine cursa \n";
	}
}
void Circuit::Race()
{
	//time = distanta / viteza;

	//pentru fiecare masina trebuie sa calculez timpul care imi trebuie sa parcurg distanta de 100 km cu viteza avgSpeed pe RAIN

	/*if (this->weather == Weather::RAIN)
		for (int i = 0; i < carCount; i++)
				*/

	float time = 0;
	for (int i = 0; i < carCount; i++) {//pentru fiecare masina
		//testez sa vad daca are suficient combustibil ca sa nu il bag in cursa degeaba
		if (checkGas(car[i]) <= length) {
			if (this->weather == Weather::RAIN) {
				time = (length / car[i]->getAverageSpeed(Weather::RAIN));
				v[i] = time;//retin pozitia
				std::cout << "Masina " << car[i] << " termina cursa in " << time;
			}
		}
		else v[i] = -1;

	}

	time = 0;
	for (int i = 0; i < carCount; i++) {//pentru fiecare masina
		if (checkGas(car[i]) <= length) {
			if (this->weather == Weather::SUNNY) {
				time = (length / car[i]->getAverageSpeed(Weather::SUNNY));
				v[i] = time;
				std::cout << "Masina " << car[i] << " termina cursa in " << time;
			}
		}
		else v[i] = -1;// il pun la coada vectorului
	}
	time = 0;
	for (int i = 0; i < carCount; i++) {//pentru fiecare masina
		if (checkGas(car[i]) <= length) {
			if (this->weather == Weather::SUNNY) {
				time = (length / car[i]->getAverageSpeed(Weather::SUNNY));
				v[i] = time;
				std::cout << "Masina " << car[i] << " termina cursa in " << time;
			}
		}
		else v[i] = -1;// il pun la coada vectorului
	}

}


void Circuit::showFinalResults()
{
	int aux;
	//cu vectorul am retinut timpul scos de o masina si l-am ordonat descrescator
	for ( int i = 0; i <5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (v[i] > v[j]) {
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
	std::cout << "topul este \n";
	for (int i = 0; i < 5; i++) {
		if (v[i] != -1) {//daca masina nu are -1, adica daca nu i s-a terminat benzina
			std::cout << " Masina " << car[i] << "\n";
		}
	}

	//nu am mai apucat sa fac sa fie frummos de genu Masina getName este pe locul X;
}
