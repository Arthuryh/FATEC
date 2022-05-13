/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int bindec(int n)
{   if(n<2) return n;
    else return 2*bindec(n/10) + n%10;
    
}

void decbin(int n )
{   if(n<2) printf("%d", n);
    else
    {   decbin(n/2);
        printf("%d", n%2);
        
    }
}

int busca(int vet[ ], int N, int indiceInicio, int procurado)
{	int i;
	for(i=indiceInicio; i < N; i++)
	{	if(procurado == vet[i])
		{	return i;
		}
	}
	return -1;
}

int buscaRec(int vet[ ], int N, int indiceInicio, int procurado)
{
    if(indiceInicio >= N) return -1; //não existe
    else if(vet[indiceInicio] == procurado) return indiceInicio; //achei
    else return buscaRec(vet, N, indiceInicio+1, procurado);
}

int maior(int vet[ ], int N, int indiceInicio)
{	int i, m = vet[indiceInicio];
	for(i=indiceInicio+1; i < N; i++)
	{	if(vet[i] > m)
		{	m = vet[i];
		}
	}
	return m;
}

int maiorRec(int vet[], int N, int indiceInicio)
{   if(indiceInicio == N-1) return vet[N-1];
    else
    {   int m = maiorRec(vet,N, indiceInicio+1);
        if(m > vet[indiceInicio]) return m;
        else return vet[indiceInicio];
    }
    
}

int main()
{   int vet[] = {3, 7, 4, 9, -2, 6, 1, 19, 42, 8};
    printf("Maior elemento: %d\n", maior(vet, 10, 0));
    printf("Maior elemento (rec.): %d\n", maiorRec(vet, 10, 0));
    return 0;
}
