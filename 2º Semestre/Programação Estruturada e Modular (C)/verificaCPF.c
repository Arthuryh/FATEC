//FATEC Ipiranga
//Disciplina: Programação Estruturada e Modular
//Aluno.....: Arthur Yoshio Hayakawa

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<locale.h>

int verificador(int cpf[], int mult[], int N) {
    int soma=0, i;
	for(i=0; i<N; i++)
	{	soma = soma + cpf[i]*mult[i];
	}
	return ((soma*10) % 11)%10;
}

bool todosRepetidos(int cpf[]) {
    int i;
    for(i=1; i<11; i++)
    {   if(cpf[0] != cpf[i]) return false;
    } return true;
}

void imprimeOrigem(int cpf[]) {
    switch (cpf[8])
    {   case 0 :
        printf ("\nEstado Emissor: Rio Grande do Sul\n");
        break;
        
        case 1 :
        printf ("\nEstado Emissor: DF, Goiás, Mato Grosso, Mato Grosso do Sul, Tocantins\n");
        break;
        
        case 2 :
        printf ("\nEstado Emissor: Amazonas, Pará, Roraima Amapá, Acre Rondônia\n");
        break;
        
        case 3 :
        printf ("\nEstado Emissor: Ceará, Maranhão, Piauí\n");
        break;
        
        case 4 :
        printf ("\nEstado Emissor: Paraíba, Pernambuco, Alagoas, Rio Grande do Norte\n");
        break;
        
        case 5 :
        printf ("\nEstado Emissor: Bahia, Sergipe\n");
        break;
        
        case 6 :
        printf ("\nEstado Emissor: Minas Gerais\n");
        break;
        
        case 7 :
        printf ("\nEstado Emissor: Rio de Janeiro, Espírito Santo\n");
        break;
        
        case 8 :
        printf ("\nEstado Emissor: São Paulo\n");
        break;
        
        case 9 :
        printf ("\nEstado Emissor: Paraná, Santa Catarina\n");
        break;
        
        default :
        printf ("\nErro no CPF, Estado não reconhecido!\n");
    }
}

/*
    Leio um CPF como texto, podendo ou não conter espaços, pontos, hifens, etc.
    Somente os digitos são levados em consideração. Zeros são acrescentados à
    esquerda caso não haja 11 caracteres.
    Os valores são colocados no vetor que é passado por parâmetro
*/
void leiaCPF(int cpf[])
{   char texto[30];
    fgets(texto, 30, stdin);
    
    int i, j=10;
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
    Imprime um CPF adicionado ponto e um hífen, como é costumeiro.
*/
void imprimeCPF(int cpf[])
{   int i;
    for(i=0; i<11; i++)
    {   printf("%d", cpf[i]);
        if(i==2||i==5) printf(".");
        if(i==8)printf("-");
    }

}

int main()
{   setlocale(LC_ALL, "Portuguese");
	int cpf[11];
	int m1[9]={10,9,8,7,6,5,4,3,2};
	int m2[10]={11,10,9,8,7,6,5,4,3,2};
	int i;
	printf("Entre com o CPF:");
	leiaCPF(cpf);
	
    if(todosRepetidos(cpf) == false
    &&verificador(cpf, m1, 9) == cpf[9] 
    &&verificador(cpf, m2, 10) == cpf[10])
    {   imprimeCPF(cpf);
        printf(" é um CPF válido.\n");
    }
	else printf("\nErro no CPF");

    imprimeOrigem(cpf);
	
	return 0;
}