/*1) a) Qual o valor de y no final do programa?
     b) Escreva um comentário em cada comando de atribuição explicando o que ele faz e o valor da variável à  esquerda do '=' após sua execução.*/

#include <stdio.h>
int main()
{
int x, y, *p, *q; //x e y são var. inteiras; p e q são var. ponteiro (end. memória)
y = 19; //y recebe 19
p = &y; //p recebe o endereço de memória de y (mostra o endereço de memória da variável y)
x = *p; //x recebe o valor que a variável ponteiro está apontando (no caso 19) 
x = 7; //x recebe 7
(*p)++; //a variável ponteiro é acrescida em 1 (resultando em 20), y agora vale 20
x--; //x é decrescida em 1 (resultando em 6)
(*p) = (*p) + x; //*p que aponta para y, recebe a soma entre o valor que *p aponta (y que vale 20) e x (que vale 6), resultando em 26 (20+6)
printf ("y = %d\n", y); //exibe o valor da variável y
q = 10; //atribui 10 para a variável q

return 0;
}