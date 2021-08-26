#include<stdio.h>

int main()
{	int l,c,n;
    printf("Qual o tamanho da matriz? ");
    scanf("%d", &n);
    int matriz[n][n];
    
    for(l=0; l<n; l++)
    {   for (c=0; c<n; c++)
        {   if(l == c) matriz[l][c] = 1;
            else matriz[l][c] = 0;
                
            printf("%d\t", matriz[l][c]);
        }
        printf("\n");
    }

    return 0;
}
