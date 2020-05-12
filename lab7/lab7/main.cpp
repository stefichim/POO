#include<iostream>
/*float operator"" _Kelvin(unsigned long long int x )
{
	//temperatura in grade celsius=temp (k)-273.15
	return x - 273.15;
}

float operator"" _Fahrenheit(unsigned long long int x)
{
	return (x - 32) * 5 / 9;
}
int main()
{
	float a = 300_Kelvin;//am 300 kelvin va trebui sa arat cat celsius am
	std::cout << a << "\n";

	float b = 50_Fahrenheit;
	std::cout << b << "\n";
	system("pause");
}*/


template <class T>
class Vector {
	T* List;
	int count;
	int vectorSize;
public:
	Vector()
	{
		this->vectorSize = 100;
		this->List = (T*)(malloc(this->vectorSize * sizeof(T)));
		this->count = 0;
	}
	void Push(T x)
	{
		if (this->count >= this->vectorSize)
		{
			this->vectorSize = this->vectorSize * 2;
			this->List = (T*)(realloc(this->List, this->vectorSize));
		}
		this->List[count++] = x;
		
		//mai tre sa pun cazul in care this->count< this->vectorSize

	}
	T Pop()
	{
		return this->List[--count];
	}
	// urmeaza metoda care sterge un element din vector

	void Delete(int index)
	{
		// pot si cu T x
		for (int i = index; i < count - 1; i++) {//parcurg vectorul
			List[i] = List[i + 1];
			}
		count--;
	}

	void Insert(int index, T x)//index e intre 0 si size curent
	{
		//prima oara vad daca trebuie sa aloc memorie pentru a putea adauga un nou element 
		if (this->count >= this->vectorSize)
		{
			this->vectorSize = this->vectorSize * 2;
			this->List = (T*)(realloc(this->List, this->vectorSize));
		}
		for (int i = count - 1; i >= index; i--) {
			List[i + 1] = List[i];
		}
		this->List[index] = x;// am pus elementul x pe pozitia index
	}

	T Count()
	{
		return count;
	}

	void Sort()//asta nu e callback function
	{
		for (int i = 0; i < count; i++) {
			for (int j = i + 1; j <= count; j++) {
				int aux = List[i];
				List[i] = List[j];
				List[j] = aux;
			}
		}

		//abia aici e callback function
		typedef void(*SortFunction)();//callback function
		SortFunction function = Sort;
		function();

		//nu inteleg ce trebuie exact sa faca aceasta functie callback. " use a callback function to provide a way to compare two elements"
	}

	T get()
	{
		return const Vector<int> &get() const;//nu stiu sigur daca asa se face si nu stiu sigur cum as putea sa verific daca e asa sau nu
	}

	void set(T x)
	{
		this->List[index] = (T*);//cred ca am setat un obiect, dar nu sunt deloc sigur ca e bine ce am facut
	}
	void Print()
	{
		for (int i = 0; i < count; i++) {
			std::cout << List[i]<<" ";
		}
		std::cout << "\n";
	}

};

int main()
{
	Vector<int> v;
	v.Push(14); v.Push(25); v.Push(31); v.Push(5); v.Push(28); v.Push(54); v.Push(10); v.Push(89);
	v.Insert(2, 105);
	//v.Delete(3);
	//std::cout << v.Pop();
	v.Print();
	std::cout << v.Count();

	v.Sort();



	/*Vector<float> f;
	f.Push(1.3); f.Push(2.7); f.Push(3.5);
	printf("%d %f\n", v.Pop(), f.Pop());*/
	system("pause");
}