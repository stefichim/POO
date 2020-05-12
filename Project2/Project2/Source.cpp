#include<iostream>
#include"NumberList.h"
using namespace std;
int main()
{
	NumberList element;
	element.Init();
	element.Add(18);
	element.Add(5);
	element.Add(10);
	element.Add(22);
	element.Sort();
	element.Print();
	system("pause");
	return 0;
}