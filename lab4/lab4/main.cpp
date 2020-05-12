#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Sort.h"
#include <initializer_list>
using namespace std;
int main()
{



	Sort toSort = Sort(5, 10, 30); //aici doar afisez elementele generate random;
	//toSort.BubbleSort(true);//daca nu ii dau niciun parametru, e ca si cum ar fi false si imi sorteaza descrescator
	toSort.InsertSort = Sort(5, 10, 30);
	toSort.Print();
	/*AM OBSERVAT CA NU POT SA AM MAI MULTI CONSTRUCTORI IN ACELASI TIMP
		DE EXEMPLU DACA VREAU SA APELEZ CONSTRUCTORUL DE LA PRIMA FUNCTIE, TREBUIE SA COMENTEZ CEILALTI CONSTRUCTORI. 
		AM CEVA EROARE CU OVERLOAD???
	*/

	/*
	NICI NU AM  INCERCAT SA APELEZ CEILALTI CONSTRUCTORI, STIU CA SUNT MULTE PROBLEME LA ACEA ALOCARE DE MEMORIE
	*/
	
	/*
	Sort  array[] = {
		{5,3,15},
		{3,8,16},
		{5,15,25}
	};

	*/
	system("pause");
	return 0;
}