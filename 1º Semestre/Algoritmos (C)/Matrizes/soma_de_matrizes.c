#include<stdio.h>
int main()
{	int l,c,n;
    int A[3][3] = {{2,3,7}, {1,0,-2}, {5,8,3}};
	int B[3][3] = {{7,2,8}, {5,9,4}, {1,2,3}};
    int soma [3][3];
    
    for(l=0; l<3; l++)
    {   for (c=0; c<3; c++)
        {   soma[l][c] = A[l][c] + B[l][c];
            printf("%d\t", soma[l][c]);
        }
        printf("\n");
    }

    return 0;
}

