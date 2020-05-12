#pragma once
#include<vector>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Propozitie
{
	char* txt;
	vector<string> cuvinte;
public:
	Propozitie();
	Propozitie(const char* txt);
	~Propozitie();

	Propozitie(const Propozitie& other);
	void Create(const char* txt);

	string operator[](int index);
	operator char*();

	int getNumberOfWords();
	bool Contains(const char* word, bool ignoreCase);

	vector<string>::iterator begin();
	vector<string>::iterator end();
};
