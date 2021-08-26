#include <stdio.h>
#include <string.h>

int main ()
{	char entrada[100];
	printf("Entre com um texto: ");
	gets(entrada);
	printf("%s", entrada);
	printf("\n\nNo texto acima ha %d caracteres.\n\nTexto de tras para frente: ", strlen(entrada));
	
	int i;
	for(i=strlen(entrada)-1; i>=0; i--) {
		printf("%c", entrada[i]);
	}
		
	return 0;
}
