#include "Propozitie.h"



Propozitie::Propozitie() 
{
	Set(txt);
}

void Propozitie::Set(const char* txt)
{
	int n = strlen(txt);//fara '\0'
	this->txt = new char[n + 1];
	strcpy(this->txt, txt);
}

