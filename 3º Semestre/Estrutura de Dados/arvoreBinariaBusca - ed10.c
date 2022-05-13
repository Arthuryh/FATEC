#include <stdio.h>
#include <stdlib.h>


/***************** Arvore.h *********************/

typedef struct _no {
    int info;
    struct _no * esq;
    struct _no * dir;
}
no;

typedef struct {
    no * raiz;
}
arvore;

/*Cria um no em uma arvore!*/
void inserir(arvore * a, int v) {
    no * novo = (no * ) malloc(sizeof(no));
    novo -> info = v;
    novo -> dir = NULL;
    novo -> esq = NULL;

    printf("\nADICIONANDO %i %x", v, novo);

    if (a -> raiz == NULL) {
        a -> raiz = novo;
    } else {
        no * aux = a -> raiz;
        while (aux != NULL) {
            if (novo -> info > aux -> info) {
                printf("->");
                //direita
                if (aux -> dir == NULL) {
                    aux -> dir = novo;
                    break;
                } else {
                    aux = aux -> dir;
                }
            } else {
                printf("<-");
                //esquerda
                if (aux -> esq == NULL) {
                    aux -> esq = novo;
                    break;
                } else {
                    aux = aux -> esq;
                }
            }
        }
    }
}

no * criarItem(int v) {
    no * novo = (no * ) malloc(sizeof(no));
    novo -> info = v;
    novo -> dir = NULL;
    novo -> esq = NULL;
    return novo;
}

/*Cria um no em uma arvore!*/
no * inserirRecursivo(no * n, int v) {
    if (n == NULL) {
        n = criarItem(v);
        printf("\nADICIONANDO RECURSIVO %i %x", v, n);
    } else {
        if (v > n -> info) {
            printf("->");
            n -> dir = inserirRecursivo(n -> dir, v);
        } else {
            printf("<-");
            n -> esq = inserirRecursivo(n -> esq, v);
        }
    }
    return n;
}

/*Cria um no em uma arvore!*/
no * removerRecursivo(no * n, int v) {
    if (n == NULL) {
        printf("\nnao encontrei vazia !!");
        return NULL;
    } else {
        if (n -> info == v) {
            printf("\nitem removido %i !!", v);
            free(n);
            return NULL;
        } else {
            if (v > n -> info) {
                printf("->");
                n -> dir = removerRecursivo(n -> dir, v);
            } else {
                printf("<-");
                n -> esq = removerRecursivo(n -> esq, v);
            }
        }
    }
}

void listar(no * item) {
    if (item != NULL) {
        printf("\n %i %x", item -> info, item);
        if (item -> esq != NULL) {
            printf("<-");
            listar(item -> esq);
        }
        if (item -> dir != NULL) {
            printf("->");
            listar(item -> dir);
        }
    }
}

void pesquisar(no * item, int v) {
    if (item != NULL) {
        if (v == item -> info) {
            printf("\n ACHEI !!! %i %x", item -> info, item);
        } else {
            if (item -> esq != NULL) {
                printf("<-");
                pesquisar(item -> esq, v);
            }
            if (item -> esq != NULL) {
                printf("->");
                pesquisar(item -> dir, v);
            }
        }
    }
}

int altura(no * item) {
    if (item == NULL) {
        return 0;
    } else {
        if (item -> esq != NULL) return altura(item -> esq) + 1;
        if (item -> dir != NULL) return altura(item -> dir) + 1;
    }
}

//1-Conte a quantidade total de elementos
int total(no * item) {
    if (item == NULL) {
        return 0;
    } else {
        return 1 + total(item -> dir) + total(item -> esq);
    }
}

//3-mostre o menor valor entre todos os itens
int menor(no * item) {
    if (item -> esq != NULL) menor(item -> esq);
    else return item -> info;
}

//2-mostre o maior valor entre todos os itens
int maior(no * item) {
    if (item -> dir != NULL) maior(item -> dir);
    else return item -> info;
}

/****************** Prog.c **********************/

int main() {

    arvore a = {
        criarItem(50)
    };

    inserirRecursivo(a.raiz, 30);
    inserirRecursivo(a.raiz, 90);
    inserirRecursivo(a.raiz, 20);
    inserirRecursivo(a.raiz, 40);
    inserirRecursivo(a.raiz, 95);
    inserirRecursivo(a.raiz, 10);
    inserirRecursivo(a.raiz, 35);
    inserirRecursivo(a.raiz, 45);

    printf("\nlistar\n=================");
    listar(a.raiz);

    int tot = total(a.raiz);
    printf("\no total de elementos eh:%i", tot);

    int men = menor(a.raiz);
    printf("\no menor elemento eh:%i", men);

    int mai = maior(a.raiz);
    printf("\no maior elemento eh:%i", mai);

    /*printf("\npesquisar\n=================");
    pesquisar(a.raiz, 213);
     
     
    printf("\npesquisar\n=================");
    pesquisar(a.raiz, 40);
     
    printf("\nremover\n=================");
     
    removerRecursivo(a.raiz, 10);
    removerRecursivo(a.raiz, 199);
    removerRecursivo(a.raiz, 45);
    removerRecursivo(a.raiz, 50);*/

    return 0;

}