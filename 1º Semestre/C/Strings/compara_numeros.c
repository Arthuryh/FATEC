#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main () 
{	char texto1[50], texto2[50];
	int i;
  
	printf ("Entre com o primeiro numero: ");
	gets (texto1);
	  
	printf ("Entre com o segundo numero: ");
	gets (texto2);
	 
	if(strlen(texto1) != strlen(texto2)) 
	printf("\nTamanhos diferentes. Nao sao iguais");
	else
	    {	for (i = 0; i < strlen(texto1); i++)
	    	{   if(texto1[i] != texto2[i])
		        {   printf("\nCaracteres diferentes. Nao sao iguais");
		            return 0;
		        }	
	        
	    	}
	    printf("\nOs textos sao iguais");
	    }
	return 0;
}
