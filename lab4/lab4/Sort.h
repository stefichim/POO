#pragma once
class Sort
{
	// add data members
private:

	int *v;//voi aloca in fiecare constructor cu malloc
	int vector_size;
	int count, k;
	int n;
public:
	// add constuctors
	Sort(int count, int mini, int maxi);
	Sort(std::initializer_list<int> count);
	Sort(int *v, int n);
	Sort(int n ...);

	void InsertSort(bool ascendent = false);
	void QuickSort(bool ascendent = false);
	void BubbleSort(bool ascendent = false);
	void Print();
	int  GetElementsCount();
	int  GetElementFromIndex(int index);
	void insertionSort(int arr[], int n);
};

