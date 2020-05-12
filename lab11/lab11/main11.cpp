#include <iostream>
#include <exception>
using namespace std;



class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

class IntComparator : public Compare
{
public:
	int CompareElements(void* e1, void* e2)
	{
		int a = *(int*)e1;
		int b = *(int*)e2;
		if (a == b)
		{
			return 0;
		}
		else if (a < b)
		{
			return -1;
		}
		else {
			return 1;
		}
	}
};

template<class T>
class TComparator : public Compare
{
public:
	int CompareElements(void* e1, void* e2)
	{
		int a = *(T*)e1;
		int b = *(T*)e2;
		if (a == b)
		{
			return 0;
		}
		else if (a < b)
		{
			return -1;
		}
		else {
			return 1;
		}
	}
};






template<class T>
class ArrayIterator
{
private:
	int Current; // mai adaugati si alte date si functii necesare pentru iterator
	T** pointer;
public:
	ArrayIterator();
	int GetCurrent() {
		return Current;
	}
	T** GetPointer() {
		return pointer;
	}
	ArrayIterator(T** pointer)
	{
		//printf("%d\n", &pointer);
		this->pointer = pointer;
		this->Current = 0;
	}
	ArrayIterator& operator++ () {
		ArrayIterator<T>it = *this;
		pointer++;
		return it;
	}
	ArrayIterator& operator -- () {
		ArrayIterator<T>it = *this;
		pointer--;
		return it;
	}
	bool operator==(ArrayIterator<T>& at) {
		return pointer == at.pointer;
	}
	bool operator!=(ArrayIterator<T>& p) {
		return pointer != p.pointer;
	}
	T* GetElement() {
		return pointer[0];
	}

};

class array_exception : public exception
{
	virtual const char* what() const throw()
	{
		return "OUT OF RANGE";
	}
};

// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
class index_invalid_exception : public exception
{
	virtual const char* what() const throw()
	{
		return "INDEX INVALID";
	}
};

template<class T>
class Array

{

private:

	T** List; // lista cu pointeri la obiecte de tipul T*

	int Capacity; // dimensiunea listei de pointeri

	int Size; // cate elemente sunt in lista

public:

	~Array() { free(this->List); } // destructor

	Array(int capacity)
	{
		this->Capacity = capacity;
		this->Size = 0;
		this->List = (T**)(malloc(capacity * sizeof(T*)));
		for (int i = 0; i < capacity; i++) {
			List[i] = (T*)malloc(sizeof(T));
		}

	}
	T& operator[](int index)
	{
		return List[index];
	}
	const Array<T>& operator+=(const T& newElem)
	{
		*this->List[Size++] = newElem;
		return *this;
		// adauga un element de tipul T la sfarsitul listei si returneaza this
	}

	const Array<T>& Insert(int index, const T &newElem) 
	{
		// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
		//prima oara vad daca trebuie sa aloc memorie pentru a putea adauga un nou element 
		if (this->count >= this->Size)
		{
			this->Size = this->vectorSize * 2;
			this->List = (T*)(realloc(this->List, this->Size));
		}
		for (int i = count - 1; i >= index; i--) {
			List[i + 1] = List[i];
		}
		this->List[index] = newElem;// am pus elementul newElem pe pozitia index
		return *this;
	}

	const Array<T>& Insert(int index, const Array<T> otherArray) 
	{
		// adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	}
	
	const Array<T>& Delete(int index)
	{
		// sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
		for (int i = index; i < count - 1; i++) {//parcurg vectorul
			List[i] = List[i + 1];
		}
		count--;
		return this;
	}

	void Sort()
	{
		for (int i = 0; i < Size - 1; i++)
			for (int j = i + 1; j < Size; j++)
			{
				//printf("%d %d\n", List[i], List[j]);
				//printf("%d %d\n", *List[i], *List[j]);
				if (*List[i] > *List[j])
				{
					swap(List[i], List[j]);
				}
			}
	}// sorteaza folosind comparatia intre elementele din T

	int BinarySearch(const T& elem, Compare* comparator)
	{
		int start = 0;
		int end = this->Size;
		while (start <= end)
		{
			int mid = (start + end) / 2;
			//if (*(this->List[mid]) == elem)
			int compareResult = comparator->CompareElements((void*)this->List[mid], (void*)&elem);
			if (compareResult == 0)
			{
				return mid;
			}
			if (compareResult == -1)
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
		return -1;
	}//  cauta un element folosind binary search si un comparator


	int Find(const T& elem)
	{
		// cauta un element in Array si returnez  true daca l-am gasit
		for (int i = 0; i < Size - 1; i++) {
			if (List[i] == elem) {
				return true;
			}
		}
		else return false;
	}
	int GetSize() {
		return this->Size;
	}

	int GetCapacity() {
		return this->Capacity;
	}

	ArrayIterator<T> GetBeginIterator()
	{
		//printf("%d - %d\n", *List[0], List[0]);
		ArrayIterator<T> myIt(&List[0]);
		return myIt;
	}

	ArrayIterator<T> GetEndIterator() {
		//printf("%d - %d\n", *List[Size], List[Size]);
		ArrayIterator<T> myIt(&List[Size]);
		return myIt;
	}

	void PrintMyArray()
	{
		for (int i = 0; i < Size; i++)
			cout << *List[i] << ' ';
		cout << "\n";
	}



};


int main()
{
	Array<int> myArray(5);
	//daca index este out of range, atunci va primi exceptie.
	int index = 8;
	array_exception index_out_of_range;
	try {
		if (index > 5)
			throw index_out_of_range;
	}
	catch (exception& e) {
		cout << "exceptie:" << e.what() << endl;
	}

	index_invalid_exception index_invalid;
	try {
		if (index <List || index>List) {
			throw index_invalid;
		}
		catch (exception& e) {
			cout << "exceptie: " << e.what() << endl;
		}

	// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie


	myArray += 5;
	myArray += 10;
	myArray += 20;
	myArray += 15;
	myArray.PrintMyArray();
	myArray.Sort();
	myArray.PrintMyArray();
	return 0;
}