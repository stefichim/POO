#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"student.h"
using namespace std;
int main()
{

	student student1;
	student student2;

	student1.setName("stefan");
	student1.setMathGrade(9);
	student1.setEngGrade(8);
	student1.setHistoryGrade(10);
	student1.toString();

	cout << "\n";

	student2.setName("Paul");
	student2.setMathGrade(8.5);
	student2.setEngGrade(8);
	student2.setHistoryGrade(11);
	student2.toString();

	compareByFirstValue(student1, student2);
	
	system("pause");
	return 0;

}