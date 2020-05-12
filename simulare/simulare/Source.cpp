#define _CRT_SECURE_NO_WARNINGS
#include"Propozitie.h"

int main()
{
	Propozitie p("Ana are mere");
	cout << p[1] << endl;//va afisa are
	cout << std::boolalpha << p.Contains("MeRE", true) << endl;//va afisa true
	cout << std::boolalpha << p.Contains("ere", false) << endl;//va afisa false
	cout << (char*)p << endl; //va afisa "Ana are mere"
	for (auto w : p) {
		cout << w << endl;//afiseaza pe rand "ana", "are", "mere"
	}

	cout << p.getNumberOfWords() << endl;//afiseaza 3
	system("pause");
	return 1;
}