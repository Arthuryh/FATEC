#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{   char texto[50];
    bool numerico = true;
    int i, ponto = 0;
    printf("Entre com algo e eu direi se e numerico ou nao: ");
    gets(texto);
    
    for(i=0; i<strlen(texto); i++)
    {   if(texto[i] == '.')
        {   if(ponto < 1) ponto++;
            else
            {   numerico = false;
                break;
            }
        }
        
        else if(texto[i]<48 || texto[i]>57 ) /*nao e numerico*/
        {   numerico = false;
            break;
        }
        
    }
    
    if(strlen(texto) == 1 && ponto == 1) printf("Nao e numerico\n");
    
    else if(numerico == true) printf("E numerico\n");
    else  printf("Nao e numerico\n");
    return 0;
}
