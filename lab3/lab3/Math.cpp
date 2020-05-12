#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include<cstdarg>
#include<iostream>
#include<string>	


Math::Math() {
	
}

int Math::Add(int x, int y) {
	return x + y;
}

int Math::Add(int x, int y, int z) {
	return x + y + z;
}

double Math::Add(double x, double y) {
	return x + y;
}

double Math::Add(double x, double y, double z) {
	return x + y + z;
}

int Math::Mul(int x, int y) {
	return x * y;
}
int Math::Mul(int x, int y, int z) {
	return x * y*z;

}

double Math::Mul(double x, double y) {
	return x * y;
}

double Math::Mul(double x, double y, double z) {
	return x * y*z;
}

int Math::Add(int count, ...) {
	int value = 0,sum=0;
	va_list v1;
	va_start(v1, count);
	for (int i = 0; i < count; i++) {
		value = va_arg(v1, int);
		sum = sum + value;
	}
	va_end(v1);
	return sum;
	//primul parametru este count(numarul de numerele pe care le voi aduna), iar dupa pun count numere!!!
}


 char* Math::Add(const char* sir1, const char* sir2) {

	if (sir1 == nullptr || sir2 == nullptr)
		return nullptr;

	int length = strlen(sir1) + strlen(sir2);//in length retin lungimea totala a celor 2 siruri
	char* temp = new char[length];//aloc memorie pt un sir de dimensiunea cumulata a celor 2 siruri!
	int i = 0;
	for (int j = 0; j < strlen(sir1); j++) {
		temp[i++] = sir1[j];
	}//am pus in temp primul sir
	for (int j = 0; j < strlen(sir2); j++) {
		temp[i++] = sir2[j];
	}//am pus in temp al doilea sir
	temp[i] = '\0';// musai ca altfel imi da bazaconii!

	return temp;
}
