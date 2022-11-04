/******************************************************************************
Nome: Arthur Yoshio Hayakawa

Crie uma lista circular que implemente um TAD: para armazenar os dados de um
de rodizio de pizzas {codigo da pizza, sabor, fatias} implemente todos os
métodos de uma lista. (2,0)

*******************************************************************************/

#include <stdio.h>

struct itm {
	int codigo_pizza;
    char sabor[30];
    int fatias;
    struct itm *anterior;
    struct itm *proximo;
} typedef pizza;

struct {
    pizza *inicio;
} typedef lista;

void adicionar(lista *p){
    pizza *novo = (pizza*)malloc(sizeof(pizza));    
    printf("\nInforme o código da pizza:");
    scanf("%i", &novo->codigo_pizza);
	printf("\nInforme o sabor:");
    scanf("%s", &novo->sabor);
    printf("\nInforme a quantidade de fatias:");
    scanf("%i", &novo->fatias);
    novo->proximo = NULL;
    if(p->inicio==NULL){
        novo->anterior=NULL;
        p->inicio = novo;
    } else {
        pizza *aux = p->inicio;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
        novo->anterior = aux;
        printf("\n aux=%x novo=%x ", aux->proximo, novo->anterior);
    }
}

void listar(lista *p){
    if(p->inicio==NULL){
        printf("\nLista Vazia !!!");
    } else {
        pizza *aux = p->inicio;
        do{
            printf("\nCodigo da pizza=%i sabor=%s fatias=%i",aux->codigo_pizza, aux->sabor, aux->fatias);
            aux = aux->proximo;
        } while(aux != NULL);
    }
}


void remover(lista *p, int codigo_pizza){
    if(p->inicio==NULL){
        printf("\nLista Vazia !!!");
    } else {
        pizza *aux = p->inicio;
        while(aux != NULL){
        	//strcmp(sabor1, sabor) == 0
            if(aux->codigo_pizza == codigo_pizza){
                if(aux == p->inicio) { //quando for o primeiro item
                    p->inicio = aux->proximo;
                } else { //quando for qualquer item 
                    pizza *aux2 = aux->anterior;
                    pizza *aux3 = aux->proximo;
                    aux2->proximo = aux3;
                    aux3->anterior = aux2;
                    
                    //aux->anterior->proximo = aux->proximo;
                    //aux->proximo->anterior = aux->anterior;
                }    
                free(aux);
                printf("\nPizza removida! cod = %i", codigo_pizza);
                break;
                // APAGAR 
            }
            aux = aux->proximo;
        }
    } 
}



int main()
{
    lista  l1 = {NULL};
    
    adicionar(&l1);
    adicionar(&l1);
    adicionar(&l1);
   
    listar(&l1);
 
    remover(&l1, 2);
    listar(&l1);

    return 0;
}
