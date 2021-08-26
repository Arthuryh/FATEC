//FATEC Ipiranga
//Disciplina: Programação Estruturada e Modular
//Aluno.....: Arthur Yoshio Hayakawa

/*
	2. Dado um número natural na base binária, transformá-lo para a base decimal.
	Exemplo: Dado 10010 a saída será 18, pois 1. 2^4 + 0. 2^3 + 0. 2^2 + 1. 2^1 + 0. 2^0 = 18.	
*/

#include<stdio.h>
int main()
{	int n, soma = 0, div, resto, peso;
	
	//entrada do valor de n
	printf("Entre com um numero binario: ");
	scanf("%d",&n);
	
	//quebrar (decompor) o número em seus dígitos por divisões sucessivas
	//multiplico cada dígito por seu peso correspondente (potência de 2)
	//acumulo (somo) todas essas multiplicações
	
	peso = 1;
	do
	{	div = n/10;
		resto = n%10;	
		n = div;
		soma = soma + peso*resto;
		
		peso = peso * 2;
	}while(div > 0);
	printf("%d", soma);
	
	return 0;
}
