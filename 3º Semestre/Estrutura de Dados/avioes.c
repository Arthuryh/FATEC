#include <stdio.h>
#include <stdlib.h>

struct aviao{
    char nome[50];
    int ident;
    struct aviao *prox;
} typedef aviao;

struct{
 aviao *primeiro;
} typedef fila;

int filaVazia(fila *f){
    if(f->primeiro == NULL) return 1;
    else return 0;
}

void colocarFila(fila *f){
 aviao *novo =  (aviao*)malloc(sizeof(aviao));
    printf("\nFILA DE DECOLAGEM");
    printf("\nDigite o nome do aviao:");
    scanf("%s", novo->nome);
    printf("\nDigite o identificador do aviao:");
    scanf("%i", &novo->ident);
    novo->prox = NULL;
    
    if(f->primeiro == NULL){
        f->primeiro = novo;
        printf("Primeiro avião da fila\n\n");
    } else {
     aviao *aux = f->primeiro;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

void removefila(fila *f){
    if(filaVazia(f)){
        printf("\nFila de aviões está vazia!");
    } else{
     aviao *aux = f->primeiro->prox;
        free(f->primeiro);
        f->primeiro = aux;
        printf("\naviao saiu da fila");
    }
}

void listarFila(fila *f){
    if(filaVazia(f)){
        printf("\nFila Vazia!");
    } else{
     aviao *aux=f->primeiro;
        while(aux != NULL){
            printf("\nAvião:%s\nIdentificador: %i\n", aux->nome,aux->ident);
            aux = aux->prox;
        }
    }
}

int main()
{   int i;
    fila f = {NULL};
    
    do {
        printf("\n\n1.Inserir aviao\n2.Remover aviao da Fila\n3.Listar Fila\n0.Sair\nEscolha a opcao:");
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