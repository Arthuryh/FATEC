#include <stdio.h>
#include <math.h>

int main()
{   int n;
    
    printf("Digite um numero: ");
    scanf("%d", &n);
    
    if(n >= 0) printf("\nPositivo"); 
    else printf("\nNegativo");
    
    return 0;
}

