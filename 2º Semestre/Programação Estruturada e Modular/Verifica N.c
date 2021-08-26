/*
	1. Dizemos que um inteiro positivo n � perfeito se for igual � soma de seus divisores positivos 
	diferentes de n. Dado um inteiro positivo n, verificar se n � perfeito.
	
	Exemplo 1: 6 � perfeito, pois 1+2+3 = 6	
	Exemplo 2: 20 n�o � perfeito, pois 1+2+4+5+10 = 22
*/

#include<stdio.h>
int main()
{	int n, i, soma;

	for(n=1; n<=10000; n++)
	{	soma = 0;
		for(i=1; i<n; i++)
		{	if(n%i == 0) // � divisivel
			soma = soma + i;
		}
		
		if(n == soma) printf("O numero %d, e perfeito\n",n);
	}
	
	
		
	
	//agora basta testar se esta soma equivale ao valor de n
	
	//else printf("Nao e perfeito");
	
	return 0;
}
