#include <stdio.h>
#include <stdlib.h>

int buscaInt(int c, int * v, int ini, int fim) {
	int meio=(ini+fim)/2;
	
	if (ini > fim) {
        return -1;
    } else if (v[meio] == c) { 
        return meio;
    } else if (v[meio] < c) { 
        return buscaInt(c, v, meio + 1, fim);
    } else {  
        return buscaInt(c, v, ini, meio - 1);
    }
}

int main(int argc, char *argv[]) {
	 int t[] = {2,4,5,7,9,11,16,27,42,45,50};
	 int tamanho = sizeof(t)/sizeof(int);
	 int ini = 0;
	 int fim = tamanho - 1;
	 int pos = buscaInt(45, t, ini, fim);
	 
	if (pos==-1) {
		printf("nao encontrado !");
	} else {
		printf("Pos = %i, valor = %i \n", pos, t[pos]);
	}
	return 0;
}



