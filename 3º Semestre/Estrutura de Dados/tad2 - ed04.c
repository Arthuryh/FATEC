#include <stdio.h>
#include <stdlib.h>


typedef struct x {
	float saldo;
	int codigo;
} Conta_Cliente;


int insere_dados(Conta_Cliente v[], int x) {
    float vl;
    printf("\n\n----NOVA CONTA----");
    printf("\nCONTA Nº:%i\n", x);
    printf("\nInsira o saldo inicial da conta:");
    scanf("%f",&vl);
    
	v[x].saldo=vl;
	 printf("\nConta Criada com sucesso!");
}

void func_saldo(float sal) {
    printf("\n\n----EXIBIÇÃO DO SALDO----");
    printf ("\nSeu saldo é de %.2f\n", sal);
}

float func_saque(float sal) {
    float saque;
    printf("\n\n----SAQUE DE VALOR----");
    printf ("\nInforme o valor que deseja sacar: ");
    scanf ("%f", &saque);
                
    if (saque > sal) {
        printf ("Saldo Insuficiente\n");
        return sal;
    }   
            
    else{
        printf ("Saque solicitado no valor de %.2f reais", saque);
        sal -= saque;
        printf ("\nO saldo atual e no valor de %.2f reais\n", sal);
        return sal;
    }
}

float func_deposito(float sal) {
    float deposito;
    printf ("\nInforme o valor que deseja depositar em reais: ");
    scanf ("%f", &deposito);
    
    sal += deposito;
    printf ("\nO saldo atual e no valor de %.2f reais\n", sal);
    return sal;
}


int main(int argc, char* argv[])
{   
    Conta_Cliente *conta;
    int ct,i;
    
	ct = 0; i = 1;
	
	conta = (float*)malloc(i*sizeof(float));
	insere_dados(conta,i);
	
    
	
	do {
	    printf ("\n\nDigite o número da conta:");
        scanf ("%i", &ct);
	    
        printf ("\n\n----MENU----\n1.Saldo\n2.Saque\n3.Deposito\n4.Nova Conta\n0.Saída\n\nEscolha uma das opções:");
        scanf ("%i", &conta[ct].codigo);

        switch (conta[ct].codigo) {
            case 1: {
                func_saldo(conta[ct].saldo);
                break;
            }
            
            case 2: {
                conta[ct].saldo = func_saque(conta[ct].saldo);
                break;
            }
            
            case 3: {
                conta[ct].saldo = func_deposito(conta[ct].saldo);
                break;
            }
            
            case 4: {
                i++;
                conta = (float*)realloc(conta,i*sizeof(float));
                insere_dados(conta,i);
                break;
            }
            
            case 0 : {
                return 0;
            }
            
            default :{
                //r = 0;
                printf ("Opção inválida\n");
            }
        
        }
    }while (conta[ct].codigo =! 0);
	

    
    return 0;
}
