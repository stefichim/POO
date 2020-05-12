#include<iostream>
#include"Canvas.h"
using namespace std;
int main()
{
	Canvas matrice(15, 15);
	matrice.DrawCircle(6, 7, 2, '*');
	matrice.printMatrix();

	system("pause");
	return 0;
}