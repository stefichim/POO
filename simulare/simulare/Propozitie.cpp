#define _CRT_SECURE_NO_WARNINGS
#include "Propozitie.h"



Propozitie::Propozitie():txt(nullptr)
{

}

Propozitie::Propozitie(const char * txt)
{
	Create(txt);
}

Propozitie::~Propozitie()
{
	if (txt != nullptr) {
		delete[] txt;
	}
}

Propozitie::Propozitie(const Propozitie & other)
{
	Create(other.txt);
}


void Propozitie::Create(const char * txt)
 {
	int n = strlen(txt);//fara '\0'
	this->txt = new char[n + 1];
	strcpy(this->txt, txt);
	
	const char delimiters[] = " ,.?!";
	char *ptr = strtok(this->txt, delimiters);//campul curent si campul de delimitatori
	while (ptr) {//while sunt intr-o zona valida
		cuvinte.push_back(ptr);//adaug cuvantul curent in vector
		ptr = strtok(NULL, delimiters);
	}
	//TODO:parsare
}

string Propozitie::operator[](int index)
{
	if (index < 0 || index >= cuvinte.size()) {
		return "";
	}
	else
		return cuvinte[index];
}

Propozitie::operator char*()
{
	string res = "";
	for (auto cuvant : cuvinte) {
		if (res.size() > 0)
			res.append(" ");
		res = res + cuvant;
	}
	strcpy(txt, res.c_str()); 
	return txt;
}

int Propozitie::getNumberOfWords()
{
	return cuvinte.size();
	//imi returneaza cate cuvinte am
}

bool Propozitie::Contains(const char * word, bool ignoreCase)
{
	if (!ignoreCase) {
		for (auto cuvant : cuvinte) {
			if (cuvant == word)
				return true;
		}
		return false;
	}
	else {
		for (auto cuvant : cuvinte) {
			if (_stricmp(cuvant.c_str(), word) == 0) {
				return true;
			}
			return false;
		}
	}
}

vector<string>::iterator Propozitie::begin()
{
	return cuvinte.begin();
}

vector<string>::iterator Propozitie::end()
{
	return cuvinte.end();
}

//cu this-> folosesc campul din clasa!! fara this folosesc parametrul dat

