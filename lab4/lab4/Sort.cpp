#include "Sort.h"
#include<iostream>
#include <time.h>  
#include <initializer_list>
#include <vector> 
#include <stdarg.h> 
#include<algorithm>


//fac si aici constructor??
Sort::Sort(int count, int mini, int maxi)//bulina 1
{
	k = count;
	int random;
	v = (int*)malloc(count * sizeof(int));
	srand(time(NULL));

	for (int i = 0; i < count; i++) {//generez count valori random intre 1 si maxi
		
		random=rand() % (maxi - mini) + mini;
		std::cout << "random: " << random << "\n";
		v[i] = random;
	}
	
}

Sort::Sort(std::initializer_list<int> count) //bulina 2
{

	v = (int*)malloc(count.size()* sizeof(int));
	this->count = sizeof(v);//INITIAL AM PUS v.size(), doar ca aveam multe erori??
	int counter = 0;
	//pentru fiecare element din lista
	for(int x : v){//NU INTELEG EXACT CE FACE ACEST FOR
		number[counter++] = x;
	}

}


void Sort::BubbleSort(bool ascendent)//o apelez ca fiind false sau true
{
	int aux;
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			if (v[i] > v[j]) {
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
}


void Sort::Print()
{
	for (int i = 0; i < k; i++)
		std::cout << v[i] << " ";
}

void Sort::InsertSort(bool ascendent)
{
	void insertionSort(int arr[], int n);
}

void Sort::insertionSort(int v[], int n)//geek
{
		int i, key, j;
		for (i = 1; i < n; i++)
		{
			key = v[i];
			j = i - 1;

			while (j >= 0 && v[j] > key)
			{
				v[j + 1] = v[j];
				j = j - 1;
			}
			v[j + 1] = key;
		}
	
}
void Sort::QuickSort(bool ascendent)
{
	void quickSort(int arr[], int low, int high);
}



int partition(int arr[], int low, int high)//quick sort luat in mare parte de pe geekforgeeks
{
	int pivot = arr[high];    
	int i = (low - 1);  
	int aux;
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++; 
			aux = arr[i];
			arr[i] = arr[j];
			arr[j] = aux;
		}
	}
	aux = arr[i+1];
	arr[i + 1] = arr[high];
	arr[high] = arr[i + 1];
		
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{

		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
Sort::Sort(int *v, int n)//pt bulina 3 doar ca nu inteleg foarte bine ce trebuie sa fac
{
	v = (int*)malloc(n * sizeof(int));// am alocat vectorul

}

int Sort::GetElementsCount()
{
	return this->count;
}

int Sort::GetElementFromIndex(int index)
{
	if (index >= 0 && index < count)
		return this->v[index - 1];
}
Sort::Sort(int n, ...)//bulina 4
{
	this->count = n;
	int val = 0;
	va_list ap;
	int i;

	va_start(ap, n);
	for (i = 0; i < n; i++) {
		this->v[i] = va_arg(ap, int);
	}
	va_end(ap);
}

