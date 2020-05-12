#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<list>
using namespace std;

int main()
{
	vector<string> vectorOfStrings;
	vectorOfStrings.push_back("test");
	vectorOfStrings.push_back("oop");
	vectorOfStrings.push_back("mere");
	vectorOfStrings.push_back("laborator10");


	

	///------cod pentru ordonare 
	for (int counter = 0; counter < vectorOfStrings.size(); counter++)
		printf("%s ", vectorOfStrings[counter].c_str());
	printf("\n");

	sort(vectorOfStrings.begin(), vectorOfStrings.end(), [](string a, string b) -> bool {
		if (a.length() == b.length())
			return a < b;
		return a.length() < b.length();
	});

	for (int counter = 0; counter < vectorOfStrings.size(); counter++)
		printf("%s ", vectorOfStrings[counter].c_str());
	printf("\n");

	//----------


	//biggest number from  a list of int

	list<int> list;
	list.push_back(150);
	list.push_back(150);
	list.push_back(44);
	list.push_back(4);
	list.push_back(190);

	auto maxim = [](list<int>)
	{
		int maxi = x.begin();
		for (int i = 0; i < x; i++)
			if (i > maxi)
				maxi = i;
		return maxi;
	};
	int val = maxim(list);
	printf("%d maxi");



	//----------------------------------------partea 3
	class myVector{
	 myVector(int capacity) 
	{
		vector = new int[capacity];
	}

	 bool Add(int value)
	 {
		 if (capacity == element) {
			 vector[element] = value;
			 element++;
			 return true;
		 }
		 else
		 {
			vector[element] = value;
			element++;
			 return true;
		 }
	 }
	 bool Delete (int index)
	 {
		 int index;
		 if (index < 0) 
			 return false;
		 if (index >= element) 
			 return false;
		 element--;
		 for (int i = index; i < element; i++)
			 vector[i] = vector[i + 1];
		 return true;
	 }

	 void Iterate()
	 {
		 for (int i = 0; i < element; i++)
			 vector[i]++;
	 }
	 void Filter()
	 {
		 for (int i = 0; i < element; i++);
			 Delete(i);
	 }
	};
	system("pause");
	return 0;
	
}