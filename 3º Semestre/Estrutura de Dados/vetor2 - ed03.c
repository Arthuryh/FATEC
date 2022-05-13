#include <stdio.h>
void func_saldo(float *p) {
    printf ("\nSeu saldo é de %.2f\n", *p);
}

void func_saque(float *p) {
    float saque;
    printf ("\nInforme o valor que deseja sacar: ");
    scanf ("%f", &saque);
                
    if (saque > *p) {
        printf ("Saldo Insuficiente\n");
    }   
            
    else{
        printf ("Saque solicitado no valor de %.2f reais", saque);
        *p -= saque;
        printf ("\nO saldo atual e no valor de %.2f reais\n", *p);
    }
}

void func_deposito(float *p) {
    float deposito;
    printf ("\nInforme o valor que deseja depositar em reais: ");
    scanf ("%f", &deposito);
    
    *p += deposito;
    printf ("\nO saldo atual e no valor de %.2f reais\n", *p);
    //printf ("Insira as notas do valor de %.2f", deposito);
}



int main(int argc, char* argv[])
{   int opcao;
    float saldo, r;
    float *p;
    
    p = &saldo;
    *p = 1000;
    
    do {
        printf ("\nEscolha uma das opções:\n1.Saldo\n2.Saque\n3.Deposito\n0.Saída\n");
        scanf ("%i", &opcao);

        switch (opcao) {
            case 1: {
                func_saldo(p);
                break;
            }
            
            case 2: {
                func_saque(p);
                break;
            }
            
            case 3: {
                func_deposito(p);
                break;
            }
            
            case 0 : {
                return 0;
            }
            
            default :{
                r = 0;
                printf ("Opção inválida\n");
            }
        
        }
    }while (opcao =! 0);
    
    return 0;
}