//FATEC Ipiranga
//Disciplina: Programa��o Estruturada e Modular
//Aluno.....: Arthur Yoshio Hayakawa

/*
	3. Dado um n�mero natural na base decimal, transform�-lo para a base bin�ria.
	Exemplo: Dado 18 a sa�da dever� ser 10010.
*/

#include<stdio.h>
int main()
{	int n =0, div, resto, peso, soma = 0;
	
	//entrada do valor de n
	printf("Entre com um numero decimal: ");
	scanf("%d",&n);
	
	peso = 1;
	do
	{	div = n/2;	
		resto = n%2;	
		n = div;
		soma = soma + peso*resto;
		peso = peso * 10;
	}while(div > 0);
	printf("%d ", soma);
	return 0;
}
