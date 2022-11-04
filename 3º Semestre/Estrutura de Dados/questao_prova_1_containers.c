#include <stdio.h>
#include <stdlib.h>

struct cx{
    char ident[20];
    char local[20];
    struct cx* proximo;
} typedef container;

struct{
    container * topo;
} typedef pilha;

void push(pilha *p){
    container *novo = (container*)malloc(sizeof(container));
    printf("\nInforme a identificação do container:");
    scanf("%s", novo -> ident);
    printf("\nInforme a localidade do container:");
    scanf("%s", novo -> local);
    novo -> proximo = p -> topo;
    p -> topo = novo;
}

void pop(pilha * p) {
    if (p -> topo != NULL) {
        container * atual = p -> topo -> proximo;
        printf("-elemento a ser removido %x ,\nproximo elemento %x", p -> topo, p -> topo -> proximo);
        free(p -> topo);
        p -> topo = atual;
    } else {
        printf("-pilha vazia");
    }
}

void mostrar(pilha * p) {
    if (p -> topo != NULL) {
        printf("\nTopo da pilha %x, identificação=%s, localidade=%s", p -> topo,
            p -> topo -> ident, p -> topo -> local);
    } else {
        printf("\npilha vazia");
    }
}

int main()
{   int i;
    pilha t = {NULL};
    
    do {
        printf("\n\n1.Inserir Container\n2.Mostrar Container do topo\n3.Remover Container\n0.Sair\nEscolha a opcao:");
        scanf("%i", &i);
        
        switch (i) {
            case 1: {
                push(&t);
                break;
            }
            
            case 2: {
                mostrar(&t);
                break;
            }
            
            case 3: {
                pop(&t);
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
