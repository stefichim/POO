#include<iostream>
#include<fstream>
#include<string>
#include <sstream>


int main()
{
	std::ifstream inFile;
	inFile.open("lab8.txt"); //deschid fisierul

	std::stringstream strStream;
	strStream << inFile.rdbuf(); //aici citesc fisierul
	std::string str = strStream.str(); //in str am continutul fisierului

	std::cout << str << "\n"; 



	/*std::istringstream iss(str);
	std::string token;
	while (std::getline(iss, token, ' '))
	{
		std::cout << token << std::endl;
	}
*/

	std::string::size_type n;
	std::string const s = str;
	n = s.find(".");//aici caut  punctul


	std::string a = str;

	// count is npos, returns [pos, size())
	std::string sub1 = a.substr(10);
	std::cout << sub1 << '\n';


		
	system("pause");
	return 0;

}