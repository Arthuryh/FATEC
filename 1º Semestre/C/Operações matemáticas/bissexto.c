#include <stdio.h>
#include <math.h>


int main()
{   int ano;
    
    printf("Digite um ano: ");
    scanf("%d", &ano);
    
    if(ano%400 == 0) printf("\nE bissexto");

    else if(ano%4 == 0 && ano%100 != 0) printf("\nE bissexto");
 
    else printf("\nNao e bissexto");

    return 0;
}

