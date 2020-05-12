#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <string> 
#include <stdlib.h>


Number::Number()
{
	
}

Number::Number(const char * value, int base)
{
	//fiindca am char myNumber[100], nu mai folosesc malloc
	//strcpy_s(myNumber, value);

	strcpy(this->myNumber, value);
	this->base = base;

}

Number::Number(const  Number& n)
{
	//aici am constructorul de copiere insa nu stiu exact ce trebuie sa scriu in el
	this->base = n.base;
	strcpy(this->myNumber, n.myNumber);
}

Number::~Number()
{
}


int Number::GetDigitsCount()
{	
	return strlen(myNumber);
}

int Number::GetBase()
{
	return base;
}

int Number::val(char c)//functie care returneaza valoarea pentru un caracter. 
{
	if (c >= '0' && c <= '9')
		return (int)c - '0';//in cazul in care e cifra
	else
		return (int)c - 'A' + 10;//in cazul in care e litera
}

int Number::toDeci( const char *str, int base)//GEEK
{
	int len = strlen(str);
	int power = 1; // Initialize power of base 
	int num = 0;  // Initialize result 
	int i;

	// Decimal equivalent is str[len-1]*1 + 
	// str[len-1]*base + str[len-1]*(base^2) + ... 
	for (i = len - 1; i >= 0; i--)
	{
		// A digit in input number must be 
		// less than number's base 
		if (val(str[i]) >= base)
		{
			printf("Invalid Number");
			return -1;
		}

		num += val(str[i]) * power;
		power = power * base;
	}

	//continui cu transofrmarea
	return num;// stiu ca daca am numarul 2F3B(16) -> 563(10)
	//ar trebui sa continui ca din baza 10 sa fac orice baza 
}


char* Number::getMyNumber()
{
	return myNumber;

}

char Number::operator[](int index)//operator pentru index
{
	return myNumber[index];
}
bool Number::operator=(const Number &n)//operator pentru asignare, =
{
	n1 = n.n1;
	return n1;
}
 Number operator+ (Number n1, Number n2) ////overload pentru +
{
	 char sir[255];
	 int numar1, numar2;
	 numar1 = n1.toDeci(n1.myNumber, n1.base);
	 numar2 = n2.toDeci(n2.myNumber, n2.base);

	 numar1 = numar1 + numar2;
	
	 int temp;
	 if (n1.base > n2.base) {
		 temp = n1.base;
	 }
	 else
		 temp = n2.base;

	n1.fromDeci(sir, temp, numar1);

	 //fac un obiect nou
	 //convertesc a.i. ambele obiecte sa fie in aceeasi baza ca sa le pot aduna
	 //acum am ambele obiecte in acceasi baza
	Number n3(sir, temp);

	return n3;
}
 Number operator- (Number n1, Number n2)//overload pentru -
 {
	 char sir[255];
	 int numar1, numar2;
	 numar1 = n1.toDeci(n1.myNumber, n1.base);
	 numar2 = n2.toDeci(n2.myNumber, n2.base);

	 numar1 = numar1 - numar2;

	 int temp;
	 if (n1.base > n2.base) {
		 temp = n1.base;
	 }
	 else
		 temp = n2.base;

	 n1.fromDeci(sir, temp, numar1);
	 Number n3(sir, temp);

	 return n3;
 }

 char Number::reVal(int num)
 {
	 if (num >= 0 && num <= 9)
		 return (char)(num + '0');
	 else
		 return (char)(num - 10 + 'A');
 }


 char* Number::fromDeci(char res[], int base, int inputNum)
 {
	 int index = 0;  // Initialize index of result 

	 // Convert input number is given base by repeatedly 
	 // dividing it by base and taking remainder 
	 while (inputNum > 0)
	 {
		 res[index++] = reVal(inputNum % base);
		 inputNum /= base;
	 }
	 res[index] = '\0';

	 // Reverse the result 
	 _strrev(res);

	 return res;
 }
 
