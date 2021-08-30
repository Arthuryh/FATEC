//FATEC Ipiranga
//Disciplina: Programação Estruturada e Modular
//Aluno.....: Arthur Yoshio Hayakawa

#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int verificador(int cpf[], int mult[], int N) {
    int soma=0, i;
	for(i=0; i<N; i++)
	{	soma = soma + cpf[i]*mult[i];
	}
	return ((soma*10) % 11)%10;
}

/*
    Leio um CPNJ como texto, podendo ou não conter espaços, pontos, hifens, etc.
    Somente os digitos são levados em consideração. Zeros são acrescentados à
    esquerda caso não haja 14 caracteres.
    Os valores são colocados no vetor que é passado por parâmetro
*/
void leiaCNPJ(int cpf[])
{   char texto[30];
    fgets(texto, 30, stdin);
    
    int i, j=13;
    for(i=strlen(texto)-1; i>=0; i--)
    {   if(texto[i]>=48 && texto[i]<=57)
        {   cpf[j] = texto[i] - '0';
            j--;
        }
    }
    //preenchendo com zeros à esquerda
    while(j>=0)
    {   cpf[j] = 0;
        j--;
    }
}
/*
    Imprime um CNPJ adicionado ponto, barra, e hífen, como é costumeiro.
*/
void imprimeCNPJ(int cnpj[])
{   int i;
    for(i=0; i<14; i++)
    {   printf("%d", cnpj[i]);
        if(i==1||i==4) printf(".");
        if(i==7) printf("/");
        if(i==11)printf("-");
    }

}

int main()
{   int cnpj[14];
	int m1[12]={5,4,3,2,9,8,7,6,5,4,3,2};
	int m2[13]={6,5,4,3,2,9,8,7,6,5,4,3,2};
	int i;
	printf("Entre com o CNPJ:");
	leiaCNPJ(cnpj);
	
    if(verificador(cnpj, m1, 12) == cnpj[12] 
    &&verificador(cnpj, m2, 13) == cnpj[13])
    {   imprimeCNPJ(cnpj);
        printf(" CNPJ valido.\n");
    }
	else printf("\nErro no CNPJ");
	
	return 0;
}