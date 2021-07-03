#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ()
{	char entrada[100];
	int i, j;
	printf("Entre com um texto: ");
	gets(entrada);
	
	for(i=0; i<strlen(entrada); i++) entrada[i] = tolower(entrada[i]);
	
	printf("Palavra toda em minusculos: %s\n", entrada);
	
	i=0;
	j=strlen(entrada)-1;
	
	while(i<j) 
	{	if(entrada[i] != entrada[j]) 
		{	printf("\nNao e palindrome!");
			return 0;
		}
		i++;
		j--;
		while(entrada[i] == ' ') i++;

		while(entrada[j] == ' ') j--;
	}
	
	printf("\nE palindrome!");	
		
	return 0;
}


