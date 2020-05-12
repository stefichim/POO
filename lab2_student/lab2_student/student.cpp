#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include <iostream>
#include<string>
using namespace std;

student::student()
{
}


student::~student()
{
}

void student::setName(string name) {
	this->name = name;
}

string student::getName() {
	return name;
}

void student::toString() {
	cout << "Numele studentului este " << name << "\n";
	cout << "Nota lui " << name << " la matematica este " << getMathGrade()<<"\n";
	cout << "Nota lui " << name << " la engleza este " << getEngGrade() << "\n";
	cout << "Nota lui " << name << " la istorie este " << getHistoryGrade() << "\n";
	cout << "media notelor este " << averageGrade(mathMark, engMark, historyMark)<<"\n";

}


//----------MATEMATICA
void student::setMathGrade(double mathMark) {
	if (mathMark >= 1 && mathMark <= 10)
		this->mathMark = mathMark;
	else this->mathMark = 0;
}

double student::getMathGrade() {
	return mathMark;
}


//----------ENGLEZA
void student::setEngGrade(double engMark) {
	if (engMark >= 1 && engMark <= 10)
		this->engMark = engMark;
	else this->engMark = 0;
}

double student::getEngGrade() {
	return engMark;
}


//-------------ISTORIE
void student::setHistoryGrade(double historyMark) {
	if (historyMark >= 1 && historyMark <= 10)
		this->historyMark = historyMark;
	else this->historyMark = 0;
}

double student::getHistoryGrade() {
	return historyMark;
}


//----------------------MEDIE NOTE

double student::averageGrade(double mathMark, double engMark, double historyMark) {

	this->mathMark = mathMark;
	this->engMark = engMark;
	this->historyMark = historyMark;
	int k = 0;
	double avg, sum = 0;
	
	//contor pentru medie
	//le bag intr-un vector
	//parcurg vectorul
	//daca elementul e diferit de 0 il adaug la suma si cresc contorul
	 
	v[0] = mathMark;
	v[1] = engMark;
	v[2] = historyMark;
	for (int i = 0; i < 3; i++)
		if (!(v[i] < 1 || v[i]>10)) {
			sum = sum + v[i];
			k++;
		}

	if (k != 0)
		 avg = sum / k;
	else return 0;
	return avg;
}




   void compareByFirstValue(student student1, student student2) {

	   if (strcmp(student1.getName(), student2.getName() == 0))
		   cout << 44;
		//probabil nu pot face strcmp pe string
	   //caut functii pentru stringuri

	   if (student1.getEngGrade() == student2.getEngGrade())
		   cout << 22;

}