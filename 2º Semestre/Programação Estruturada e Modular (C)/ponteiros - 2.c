//2) Comente o trecho abaixo linha-a-linha e mostre o que será impresso pelo comando printf:

#include <stdio.h>
int main()
{
    int a = 10, b = 7, c; //a recebe 10, b recebe 7, c não inicializado
    int *p = &a; //p recebe o endereço de a
    int *q = &b; //q recebe o endereço de b
    int *r = &c; //r recebe o endereço de c
    *r = *p; //r recebe o valor que p aponta (10)
    *p = *q; //p recebe o valor que q aponta (7)
    *q = *r; //q recebe o valor que r aponta (10)
    printf("%d %d", a, b); //exibe o valor de a e b (a=7 e b=10)

return 0;
}
