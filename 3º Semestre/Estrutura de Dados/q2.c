/******************************************************************************
2-Implemente uma lista duplamente encadeada para simular uma rede social de pessoas
conhecidas, implemente todas as funções

OBS: Somente a função de exclusão não esta funcionando :c
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa {
    char nome[30];
    struct pessoa *anterior;
    struct pessoa *proximo;
};

typedef struct pessoa item;


item *criaLista(){
	item *lista=(item*)malloc(sizeof(item)); //ponteiro e um end na memoria
	lista->proximo = NULL;
	return lista;
}

int listaVazia(item *p)
{   if(p->proximo==NULL){
 		return 1;	
	} else {
		return 0;
	}
}

void colocaNaLista(item *lista)
{   item *novo=(item*)malloc(sizeof(item));
	printf("Informe um nome:"); 
	gets(novo->nome);
	novo->proximo = NULL;  
	novo->anterior = NULL;  
	
	if(listaVazia(lista)==1){
		lista->proximo = novo;
		novo->anterior = lista;	
	} else {
		item *temp = lista->proximo;
		while(temp->proximo != NULL){
			temp = temp->proximo;
		}
		temp->proximo = novo;
		novo->anterior = temp;
	}
}

void colocaInicioLista(item *lista)
{   item *novo=(item*)malloc(sizeof(item));
	printf("Informe um nome:"); 
	gets(novo->nome);
	novo->proximo = NULL;  
	novo->anterior = lista;	
	
	if(listaVazia(lista)==1){
		lista->proximo = novo;	
	} else {
		//atualiza o proximo elemento do item recem criado com o primeiro atual
		novo->proximo = lista->proximo;
		//atualizou o endere�o do primeito atual com endere�o do novo
		lista->proximo->anterior = novo;
		lista->proximo = novo;
	}
}

void removerLista(item *lista, char nm[])
{   if(listaVazia(lista)==0){
   		item *temp = lista->proximo; //end do primeiro item associado
		item *anterior = lista; //end da cabe?da lista
		while(temp != NULL){
			if(temp->nome==nm){
				anterior->proximo = temp->proximo;
				temp->proximo->anterior = anterior;
				printf("Item Removido %x %s \n", temp, temp->nome);
				free(temp);
				break;			
			} else {
				anterior = temp;
				temp = temp->proximo;
			}
		}
   }
}

void exibe(item *lista)
{   item *temp = lista->proximo;
	while(temp != NULL){
		printf("Item %x %s Ant=%x prox=%x \n", temp, temp->nome, temp->anterior, temp->proximo);
		temp = temp->proximo;
	}
}

void total(item *lista)
{
	int comprimento = 0;
   	item *temp = lista->proximo;
	while(temp != NULL){
		comprimento++;
		temp = temp->proximo;
	}
	printf("Total de itens : %i \n", comprimento);
}

int main(int argc, char *argv[])
{
    char name[30];
    item *lista = criaLista();
	colocaNaLista(lista);
	colocaNaLista(lista);
	colocaNaLista(lista);
	colocaInicioLista(lista);
	exibe(lista);
	total(lista);
	printf("Digite um nome a ser removido: ");
	gets(name);
	removerLista(lista,name);
	exibe(lista);
	printf("Digite um nome a ser removido: ");
	gets(name);
	removerLista(lista,name);
	total(lista);

    return 0;
}