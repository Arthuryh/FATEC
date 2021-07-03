#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{   int altobaixo, inicio=1, meio=500, fim=1000, cont=1;
    printf("Pense em um numero entre 1 e 1000!!\n");
    do{     printf("\nO numero e %d? 0(SIM) ou o palpite foi 1(ALTO) 2(BAIXO): ", meio);
            scanf("%d",&altobaixo);
            if(altobaixo == 0) altobaixo = 0;
            else if(altobaixo == 1)
            {   cont++;
                fim = meio-1;
                meio = (inicio+fim)/2; }
            else if(altobaixo == 2)
            {   cont++;
                inicio = meio+1;
                meio = (inicio+fim)/2; }
            else
            {   printf("Entrada Invalida. 0(SIM) o numero chutado foi 1(ALTO) 2(BAIXO): ");
                scanf("%d",&altobaixo); }
        }while(altobaixo > 0);
    printf("\nCom %d palpites, descobri que o numero e %d!\n", cont, meio);
    return 0;
}
