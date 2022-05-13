/******************************************************************************
1-Implemente uma lista circular que represente o gerenciamento de processamento
de um sistema operacional, além das funções para adicionar, remover e listar,
implemente uma função chamada de processar, que fara um laço enquanto tiver elementos
na lista e deduzira -1 do atributo carga do TAD processo, quando carga for igual a
0 chame o metodo para remover o Processo da lista. Removendo todos os processos da lista
encerre o laço




*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*typedef struct processo {
  int pid;
  struct processo *prox;
  
} Processo;*/

struct processo {
    int pid;
    struct processo *proximo;
    int carga;
} typedef Processo;

struct {
    Processo *inicio;
} typedef lista;

void adicionar(lista *p){
    Processo *novo = (Processo*)malloc(sizeof(Processo));
    printf("\nInforme um pid:");
    scanf("%i",&novo ->pid);
    printf("Informe uma carga para esse processo:");
    scanf("%i",&novo ->carga);
    novo->proximo = p->inicio;
    
    if(p->inicio==NULL){
        p->inicio=novo;
    } 
    
    else {
        Processo *aux = p->inicio;
        while(aux->proximo != novo->proximo && aux->proximo!=NULL){
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
        Processo *aux = p->inicio;
        do{
            printf("\npid atual=%i\nproximo pid=%x\n", aux->pid, aux->proximo->pid);
            aux = aux->proximo;
        }while(aux != p->inicio);
    }
}

void remover(lista *p, int pid){
    if(p->inicio == NULL){
        printf("Lista Vazia!!!\n");

    }
    
    else {
        Processo *aux = p->inicio;
        Processo *penultimo;
        do{
            if(aux -> pid == pid){ //quando for primeiro Processo
                if(aux == p->inicio) {
                    Processo *proximo = aux->proximo;
                } else { //quando for qualquer Processo
                    penultimo->proximo = aux->proximo;
                }
                    
                free(aux);
                printf("\nCódigo removido %i\n",pid);
                break;
                //APAGAR
            }
            penultimo = aux;
            aux = aux->proximo;
        }while(aux != p->inicio);
    }
}

void processar(lista *p){
    if(p->inicio == NULL){
        printf("Lista Vazia!!!\n");
    }
    
    else {
        Processo *aux = p->inicio;
        Processo *aux2;
        Processo *penultimo;
        int pid = aux->pid;
        do{
            if(aux -> pid == pid){ //quando for primeiro Processo
                if(aux == p->inicio) {
                    Processo *proximo = aux->proximo;
                } else { //quando for qualquer Processo
                    penultimo->proximo = aux->proximo;
                }
                
                while(aux->carga > 0){
                    printf("\npid=%i Carga atual=%i\nRemovendo 1 da carga\n",aux->pid, aux->carga);
                    aux->carga = aux->carga-1;
                }
                
                aux2 = aux->proximo;
                free(aux);
                printf("\nCódigo removido %i",pid);
                //APAGAR
                aux = aux2;
            }
            penultimo = aux;
            pid = aux->pid;
        }while(aux != p->inicio);
    }
}


int main()
{
    lista l1 = {NULL};
    
    adicionar(&l1);
    adicionar(&l1);
    adicionar(&l1);
    adicionar(&l1);
    adicionar(&l1);
    
    listar(&l1);
    
    remover(&l1,2);

    processar(&l1);

    return 0;
}

