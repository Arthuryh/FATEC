#include <stdio.h>
#include <stdlib.h>

struct conta{
    char nome[50];
    int agencia;
    int conta;
    float saldo;
    struct conta *prox;
} typedef cli;

struct{
    cli *primeiro;
} typedef fila;

int filaVazia(fila *f){
    if(f->primeiro == NULL) return 1;
    else return 0;
}

void colocarFila(fila *f){
    cli *novo = (cli*)malloc(sizeof(cli));
    printf("\nINSERIR CLIENTE NA FILA");
    printf("\nDigite o nome do cliente:");
    scanf("%s", novo->nome);
    printf("\nDigite a agencia do cliente:");
    scanf("%i", &novo->agencia);
    printf("\nDigite a conta do cliente:");
    scanf("%i", &novo->conta);
    printf("\nDigite o saldo do cliente:");
    scanf("%f", &novo->saldo);
    printf("\n");
    novo->prox = NULL;
    
    if(f->primeiro == NULL){
        f->primeiro = novo;
        printf("Primeiro da fila\n\n");
    } else {
        cli *aux = f->primeiro;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

void removefila(fila *f){
    if(filaVazia(f)){
        printf("\nFila está vazia!");
    } else{
        cli *aux = f->primeiro->prox;
        free(f->primeiro);
        f->primeiro = aux;
        printf("\nCliente saiu da fila");
    }
}

void listarFila(fila *f){
    if(filaVazia(f)){
        printf("\nFila Vazia!");
    } else{
        cli *aux=f->primeiro;
        while(aux != NULL){
            printf("\nCliente: %s\nAgencia: %i Conta: %i Saldo: %.2f\n", aux->nome,aux->agencia,aux->conta,aux->saldo);
            aux = aux->prox;
        }
    }
}

int main()
{   int i;
    fila f = {NULL};
    
    do {
        printf("\n\n1.Inserir cliente\n2.Remover cliente da Fila\n3.Listar Fila\n0.Sair\nEscolha a opcao:");
        scanf("%i", &i);
        
        switch (i) {
            case 1: {
                colocarFila(&f);
                break;
            }
            
            case 2: {
                removefila(&f);
                break;
            }
            
            case 3: {
                listarFila(&f);
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
    }while (i =! 0);
        
    return 0;
}