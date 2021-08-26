#include <stdio.h>

int main()
{   
    int A[]= {1,2,3,4,5}, B[]= {2, -2, 0, 4, -2};
    int prod_escalar = 0;
    
    prod_escalar = A[0]*B[0] + A[1]*B[1] + A[2]*B[2] + A[3]*B[3] + A[4]*B[4];
    printf("O produto escalar vale %d", prod_escalar);
   
    return 0;
}

