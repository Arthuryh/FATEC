#include <stdio.h>
#include <stdlib.h>

int buscaSequencialRecursiva(int x, int tam, int v[], int idx) {
    if (idx == tam) { 
       return -1;
    }  else if (v[idx] == x) { 
        return idx; 
    } else {
        return buscaSequencialRecursiva(x, tam, v, idx + 1); 
    }
}

int main(int argc, char *argv[]) {
	int vet[] = {3, 5, 7, 1, 27, 1, 13, 6, 17, 23};
	int tamanho =  sizeof(vet)/sizeof(int);
	int idx = 0;
	int pos = buscaSequencialRecursiva(23, tamanho, vet, idx);
	
	if (pos==-1) {
		printf("nao encontrado !");
	} else {
		printf("Pos = %i, valor = %i \n", pos, vet[pos]);
	}
	return 0;
}

