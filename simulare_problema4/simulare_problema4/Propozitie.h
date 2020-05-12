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
	void Set(const char* txt);
	~Propozitie();
};

