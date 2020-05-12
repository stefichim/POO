#include<iostream>

 template<typename T1, typename T2>

 class Map {
	 T1 key[100];
	 public:T2 value[100];
	
	Map() //constructor
	 {
		 for (int i = 0; i < 100; i++) {
			 key[i] = -1;
		}
	 };
	
	 int searchKey(T1 key)
	 {
		 for (int i = 0; i < 100; i++) {
			 if (key == this->key[i]) {
				 return i;//returnez pozitia din vector
			 }
		}
		 return -1;//nu exista cheia 
	 }

	 //-------------------------------------------------------------
	 void Set(const T1& key, T2& value)
	 {
		 //functie care asociaza cheii o valoare
		// caut indexul corespunzator cheii;
		//la pozitia i din value, setez valoarea
		 for (int i = 0; i < 100; i++)
			 key[i] = value;
	 }

	 bool Get(const T1& key, T2& value)
	 {
		 //search key si reutrnez valoarea de la cheia returnata
		 for (int i = 0; i < 100; i++) {
			 if (key == -1)
				 return false;
			 else//copiez valoarea pentru cheie
				 value[i] = key;
		 }
		 return true;
	 }

	 int Count()
	 {
		 int count=0;
		 for (int i = 0; i < 100; i++) {
			 if (value[i] != -1) {//daca am valoarea
				 count++;
			 }
		 }
		 return count;
	 }

	 bool Delete(const T1& key)
	 {

		 // pot si cu T x
		 for (int i = 0; i <100 ; i++) {//parcurg vectorul
			 if (key[i] != -1)//daca exista cheie
				 key[i] = key[i + 1];// sterg cheia
		 }
	 }

	 //-------
	 T2& operator[](T1 _key)
	 {
		 int index = searchKey(_key); //in index retin
		 if (index == -1) {
			 for (int i = 0; i < 100; i++) {
				 if (key[i] == -1) {//vectorul key!!	
					 key[i] = _key;//in vectorul key pe pozitia i pun valoarea cheii (_key)
					 return value[i];
				 }
			 }
		 }
		 else {
			 return value[index];
		 }
	 }
};


 


int main()
{ 
	Map<int, int> nume;
	nume[0] = 15;
	nume[9] = 44;
	nume[1] = 22;


	for (int i = 0; i < 100; i++)
		std::cout << nume[i]<<" ";

	system("pause");

}