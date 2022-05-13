https: //www.onlinegdb.com/exIUo8ndH

    #include <stdio.h>

    #include <stdlib.h>

    /*****************Arvore.h *********************/

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

/*Cria um no em uma arvore!*/
void remover(arvore * a, int valor) {
    printf("\nREMOVENDO %i", valor);
    if (a -> raiz == NULL) {
        printf("Arvore vazia !!");
    } else {
        no * aux = a -> raiz;
        no * anterior = NULL;
        while (aux != NULL) {
            if (valor == aux -> info) {
                printf("item removido !");
                free(aux);
                break;
            } else {
                anterior = aux;
                if (valor > aux -> info) {
                    printf("->"); //direita
                    aux = aux -> dir;
                } else {
                    printf("<-"); //esquerda
                    aux = aux -> esq;
                }
            }
        }
        if (anterior != NULL && valor > anterior -> info) {
            anterior -> dir = NULL;
        } else {
            anterior -> esq = NULL;
        }
    }
}

int altura(arvore * a) {
    int alturaD = 0, alturaE = 0;
    no * aux = a -> raiz;
    while (aux != NULL) {
        //direita
        if (aux -> dir == NULL) {
            aux = a -> raiz;
            break;
        } else {
            alturaD++;
            aux = aux -> dir;
        }
    }

    while (aux != NULL) {
        //esquerda
        if (aux -> esq == NULL) {
            break;
        } else {
            alturaE++;
            aux = aux -> esq;
        }
    }

    if (alturaE > alturaD) printf("\nA altura dessa arvore eh: %i\n", alturaE);
    else printf("\nA altura dessa arvore eh: %i\n", alturaD);
}

/******************Prog.c **********************/

int main() {

    arvore a = {
        NULL
    };

    inserir( & a, 50);
    inserir( & a, 30);
    inserir( & a, 90);
    inserir( & a, 20);
    inserir( & a, 40);
    inserir( & a, 95);
    inserir( & a, 10);
    inserir( & a, 35);
    inserir( & a, 45);

    altura( & a);

    remover( & a, 10);
    remover( & a, 199);
    remover( & a, 45);

    altura( & a);
    return 0;

}