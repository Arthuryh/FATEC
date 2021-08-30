#include <stdio.h>
#include <string.h>

int main()
{   char texto[30];
    int cpf[11];
    fgets(texto, 30, stdin);
    
    int i, j=10;
    for(i=strlen(texto)-1; i>=0; i--)
    {   if(texto[i]>=48 && texto[i]<=57)
        {   cpf[j] = texto[i] - '0';
            j--;
        }
    }

    while(j>=0)
    {   cpf[j] = 0;
        j--;
    }
    
    for(i=0; i<11; i++)
    {
        printf("%d", cpf[i]);
        if(i==2||i==5) printf(".");
        if(i==8)printf("-");
    }

    return 0;
}