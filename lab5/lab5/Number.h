#pragma once
class Number
{
private:
	// add data members
	char myNumber[100];
	int base;//
	int size;
	char * value, str;
	int n1, n2;
public:
	Number();
	Number(const char * value, int base); // where base is between 2 and 16 
	//Number(long long value, int destBase);//e optional?
	Number(const Number& n);//constructor de copiere!!
	~Number();

	// add operators and copy/move constructor
	Number(const Number&& n);//constructor de mutare


	friend Number  operator+(Number n1,Number n2);
	friend Number  operator-(Number n1, Number n2);

	
	char operator[](int index);

	bool operator<(const Number &n1);
	bool operator<=(const Number &n1);
	bool operator>(const Number &n1);
	bool operator>=(const Number &n1);
	bool operator=(const Number &n); 
	bool operator!=(const Number &n1);



	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
	//int baza_b_10(int *str, int base);
	int toDeci( const char *str, int base);//functie care converteste din orice baza in decimal (GEEK)
	int val(char c);
	char* getMyNumber();
	char reVal(int num);
	char* fromDeci(char res[], int base, int inputNum); //functie care converteste din decimal in orice baza( GEEK)
};

