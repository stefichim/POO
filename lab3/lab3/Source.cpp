#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Math.h"

using namespace std;
int main()
{
	Math add1, mul1;
	cout << add1.Add(2, 3) << endl;
	cout << add1.Add(2, 3, 6) << endl;
	cout << add1.Add(2.2, 3.6) << endl;
	cout << add1.Add(2.0, 3.2, 6.2) << endl;


	cout << mul1.Mul(2, 6) << endl;
	cout << mul1.Mul(2, 3, 6) << endl;
	cout << mul1.Mul(3.2, (double) 6) << endl;
	cout << mul1.Mul(2.6, 3.9, 6.2) << endl;
	cout << endl;
	
	cout << add1.Add(5, 1, 2, 3, 4, 5) << '\n';

	printf("%s", add1.Add(nullptr, "text"));
	system("pause");
	return 0;

}