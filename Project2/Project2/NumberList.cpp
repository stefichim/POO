#define _CRT_SECURE_NO_WARNINGS
#define NULL 0
#include<iostream>
#include "NumberList.h"
using namespace std;

NumberList::NumberList()
{

}


NumberList::~NumberList()
{
}

void NumberList::Init() {
	this->count = 0;//setez counter-ul pe 0!!
}

bool NumberList::Add(int x) {
	
	if (this->count >= 10)
		return false;
	else {

		this->numbers[this->count++] = x;
		return true;
	}
}



void NumberList::Sort() {
	
	int aux;
	for(int i=0; i<count;i++)
		for (int j = i + 1; j <= count; j++) {
			if (numbers[i] < numbers[j]) {
				aux = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = aux;
			}
		}
}

void NumberList::Print() {

	for (int i = 0; i < count; i++)
		cout << numbers[i] << " ";
}