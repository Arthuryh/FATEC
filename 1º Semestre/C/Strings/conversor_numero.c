#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*Este programa pega um numero e vai aumentando suas
casas decimais até chegar no numero digitado, somando
numero por numero, e conforme vai passando as casas
multiplicando por 10*/

int main()
{   char texto[50];
    int i, multiplicador=1,soma=0;
    printf("Entre com um numero: ");
    gets(texto);
    
    for(i=strlen(texto)-1;i>=0; i--)
    {   printf("\nDigito analisado:%d\n",texto[i]-48);
        printf("Multiplicador:%d\n",multiplicador);
        soma = soma + (texto[i] - 48)*multiplicador;
        printf("Soma parcial:%d\n",soma);
        multiplicador = multiplicador*10;
    }
    
    printf("\nNumero convertido:%d\n",soma);
   
    return 0;
}
