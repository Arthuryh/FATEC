#include <stdio.h>
#include <stdlib.h>

struct itm {
    int min,max;
    struct itm *proximo;
} typedef item;

struct {
    item *inicio;
} typedef lista;

void adicionar(lista *p){
    int auxnum;
    item *novo = (item*)malloc(sizeof(item));
    printf("\nInforme um numero:");
    scanf("%i",&novo ->min);
    
    printf("\nInforme outro numero:");
    scanf("%i",&novo ->max);
    
    if(novo->min > novo->max ||novo->max < novo->min){
        auxnum = novo->min;
        novo->min = novo->max;
        novo->max = auxnum;
    }
    novo->proximo = NULL;
    
    if(p->inicio==NULL){
        p->inicio=novo;
    } 
    
    else {
        item *aux = p->inicio;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}

void listar(lista *p){
    if(p->inicio == NULL){
        printf("Lista Vazia!!!\n");

    }
    
    else {
        item *aux = p->inicio;
        while(aux != NULL){
            printf("\n\nmin=%i", aux->min);
            printf("\nmax=%i", aux->max);
            aux = aux->proximo;
        }
        
    }
}


int main()
{
    lista l1 = {NULL};
    
    adicionar(&l1);
    adicionar(&l1);
    adicionar(&l1);
    
    listar(&l1);

    return 0;
}
