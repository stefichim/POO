#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int stringToInt(char mystring[])
{
	int c, n;
	n = 0;
	for (c = 0; mystring[c] != '\0'; c++)
		n = n * 10 + mystring[c] - '0';
	return n;
}
int main()
{
	int n, sum = 0;
	char mystring[100];
	FILE *pFile;
	char ch;
	pFile = fopen("in.txt", "r");
	if (pFile == NULL)
	{
		printf("File is not available \n");


	}
	else
	{
		while (fgets(mystring, 100, pFile) != NULL)
		{
			mystring[strlen(mystring) - 1] = '\0';
			n = stringToInt(mystring);
			sum = sum + n;
		}
	}

	printf("%d", sum);
	system("pause");
	fclose(pFile);
	
	return 0;
}
