#include<stdio.h>
int main()
{	int l,c;
    int A[3][4] = {{2,3,7,4}, {1,0,-2,4}, {5,8,3,4}};
    
    
    for(c=0; c<4; c++)
    {   for (l=0; l<3; l++)
        {   printf("%d\t", A[l][c]);
        }
        printf("\n");
    }

    return 0;
}
