#include <stdio.h>
#include <math.h>


int main()
{	float a,b,c;
    
    printf("Digite o A: ");
    scanf("%f", &a);
    printf("Digite o B: ");
    scanf("%f", &b);
    printf("Digite o C: ");
    scanf("%f", &c);
    
    
    if(a < b+c && b < a+c && c < a+b) 
	{	printf("\nE triangulo");
        
        if(a*a == b*b+c*c || b*b == a*a+c*c || c*c == a*a+b*b) printf("\nE triângulo retangulo");
        
        else printf("\nNao e triangulo retangulo");
        
        if (a == b && b == c) printf("\nE triangulo equilatero");
        
        else if (a != b && a!=c && b!=c) printf("\nE triangulo escaleno");
        
        else printf("\nE triangulo isosceles");
        
    }
    
    else printf("\nNao e triangulo");
    
    return 0;
}
