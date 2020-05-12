#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char *sir[25], str[500];
    char *aux;
    scanf("%[^\n]",str);// am citit de la tastatura
    //puts(str);// am bagat in sirul str continutul
    int count=0,i,j;
    char *p;
    p = strtok(str, " ");
    while(p!=NULL)
    {

        sir[count++]=p;//pun in vector cuvantul citit si cresc contorul
        p=strtok(NULL, " ");//caut mai departe
    }

    //pentru fiecare cuvant, trebuie sa ordonez in functie de dimensiunea cuvantului
    //pentru fiecare cuvant de aceeasi lungime trebuie sa-l ordonez
    for(i=0; i<count; i++)
        for(j=0; j<i; j++)
        {
            if(strlen(sir[i])>strlen(sir[j]))
            {
                aux=sir[i];
                sir[i]=sir[j];
                sir[j]=aux;
            }
        }


    for(i=0; i< count; i++)
        printf("%s\n", sir[i]);
    return 0;
}


/*
scanf(ca sa citesc cuvintele)
sortare dupa lungime descrescator si alfabetic
printf

citesc cuvintee
*/

