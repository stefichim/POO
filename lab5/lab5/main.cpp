#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Number.h"
int main()
{

	//------------------------------------------------------IMPORTANT-----------------------------------------------------------

	/*-------1.Am reusit sa imi fac constructorul avand numarul si baza ca parametrii
	---------2.Am reusit sa fac constructorul de copiere
	---------3.Am gasit 2 functii care imi convertesc din baza X in decimal si invers
	---------4.Cred ca am reusit sa suprascriu operator+, operator- si operator=, doar ca primesc ceva eroare de LINK si nu pot sa verific exact
	---------5. Am suprascris operator[].
	---------6. Am scris functia getDigitsCount si getBae
	---------7. Daca stergi acele metode de overload (+,-,=), codul va compila

	-------------------------------M-as bucura daca ai reusi sa-mi dai un feedback pe ceea ce am scris, stiu ca sunt multe prostii.
	*/



	//fac un obiect care imi retine numarul pe care i l-am dat in baza 10
	Number number1("10110010", 2);//178
	Number numberX = number1;// in number2 voi pune ceea ce am in number 1
	Number number2("734", 8);
	Number number3("FF", 16);


	printf("n1 has %d digits and it is written in base %d\n", number1.GetDigitsCount(), number1.GetBase());

	printf("n1 has %d digits and it is written in base %d\n", number2.GetDigitsCount(), number2.GetBase());

	printf("n1 has %d digits and it is written in base %d\n", number3.GetDigitsCount(), number3.GetBase());
	
	
	for (int tr = 0; tr < number1.GetDigitsCount(); tr++)
	{
		printf("n1[%d]=%c\n", tr, number1[tr]);
	}

	for (int tr = 0; tr < number2.GetDigitsCount(); tr++)
	{
		printf("n1[%d]=%c\n", tr, number2[tr]);
	}

	number1 = (number2 + number3 - number1) + number1;
	
	//std::cout<<number1.toDeci("F5F",16);
	
	system("pause");
	return 0;
}