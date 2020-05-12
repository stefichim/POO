#include<string>
#pragma once
using namespace std;
class student
{
	string name;
	double mathMark;
	double engMark;
	double historyMark;
	double v[3] = { 0 };

public:
	
	student();
	~student();

	void setName(string name);
	string getName();
	void toString();

	void setMathGrade(double mathMark);
	double getMathGrade();


	void setEngGrade(double engMark);
	double getEngGrade();

	void setHistoryGrade(double historyMark);
	double getHistoryGrade();

	double averageGrade(double MathMark, double engMark, double historyMark);

	friend void compareByFirstValue(student student1, student student2);

};

