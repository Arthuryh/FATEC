#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main () 
{	char texto1[50], texto2[50];
  	bool achei = false;
	  
	int i,j;
	  
	printf ("Entre com o primeiro numero:");
	gets (texto1);
	  
	printf ("Entre com o segundo numero:");
	gets (texto2);
	 
	    for (i = 0; i <= strlen(texto1)-strlen(texto2); i++)
	    {   j = 0;
	        while (j< strlen(texto2) && texto1[i+j] == texto2[j]) j++;
	        
	        if(j == strlen(texto2))
	        {	printf("\nAchei no indice: %d", i);      
	            achei = true;
	        }      
	    }
	    
	    if(!achei) printf("\nNão encontrei o valor buscado em nenhum dos indices");
	    
	return 0;

}
