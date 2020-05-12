#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Car.h"
#include"Circuit.h"
#include"Dacia.h"
int main()
{
	Circuit circuit;
	circuit.setLength(100);
	circuit.addCar(new Dacia());
	system("pause");
	return 0;
}