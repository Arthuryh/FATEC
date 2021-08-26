#include <stdio.h>
#include <math.h>

int main()
{   float a,b,c,delta,x1,x2;
    
    printf("Digite o coeficiente A: ");
    scanf("%f", &a);
    printf("Digite o coeficiente B: ");
    scanf("%f", &b);
    printf("Digite o coeficiente C: ");
    scanf("%f", &c);
    
    delta = (pow(b,2) - (4*a*c));
    
    if(a == 0) printf("\nNao e equaçao do segundo grau!!!");
    
    else if(delta > 0) 
	{	x1 = (-1*b) + sqrt(delta)/(2*a);
        x2 = (-1*b) - sqrt(delta)/(2*a);
       
        printf("\nX1 = %.1f ",x1);
        printf("\nX2 = %.1f ",x2);
    }
    
     else if(delta == 0) 
	 {	x1 = (-1 * b) / (2*a);
         printf("\nX = %.1f ",x1);
     }
    
    else printf("\nNao tem raizes reais");
    
    return 0;
}
