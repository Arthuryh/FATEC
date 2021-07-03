#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<stdbool.h>

#define AGUA 0
#define NAVIO 1
#define TIRONAGUA 10
#define TIRONAVIO 11

int main()
{   int i, j, cont;
    bool estrategia = false;
    int iAnterior, jAnterior, partesNavioDerrubadas;
    /*inicializando a semente aleatória com o relogio da maquina*/
    srand(time(NULL));
    
    
    int matPc[10][10], matHuman[10][10];
    /*inicializando a matriz com zeros (AGUA)*/
    for(i=0; i<10; i++)
    for(j=0; j<10; j++)
    {   matPc[i][j] = AGUA;
        matHuman[i][j] = AGUA;
    }
    
    /*sorteio das 6 posições do navio da maquina*/
    for (cont=0; cont<6; cont++)
    {   do {
            i = rand()%10; /*linha vai de 0 a 9*/
            j = rand()%8; /*coluna vai de 0 a 7*/
        }while(matPc[i][j]==NAVIO || matPc[i][j+1]==NAVIO || matPc[i][j+2]==NAVIO);
        matPc[i][j] = NAVIO;
        matPc[i][j+1] = NAVIO; /*coluna seguinte*/
        matPc[i][j+2] = NAVIO; /*coluna seguinte da seguinte*/
    }
    
    /*Imprimindo o tabuleiro da maquina
    printf("Imprimindo tabuleiro maquina:\n");
    printf("   0 1 2 3 4 5 6 7 8 9\n");
    for(i=0; i<10; i++)
    {   printf("%d |", i);
        for(j=0; j<10; j++)
        {   if(matPc[i][j]==AGUA)printf(" |");
            else if(matPc[i][j]==NAVIO)printf(" |");
            else if(matPc[i][j]==TIRONAGUA)printf("A|");
            else if(matPc[i][j]==TIRONAVIO)printf("X|");
        }
        printf("\n");
    } ****NÃO NECESSARIO MOSTRAR TABULEIRO DA MAQUINA*/
    
    /*TITULO DO JOGO*/
    printf("8888   88888  88888  88888  8      8   8  88888\n");
    printf("8   8  8   8    8    8   8  8      8   8  8   8\n");
    printf("8888   88888    8    88888  8      88888  88888\n");
    printf("8   8  8   8    8    8   8  8      8   8  8   8\n");
    printf("8888   8   8    8    8   8  88888  8   8  8   8\n\n");

    printf("         8   8  88888  8   8  88888  8\n");
    printf("         88  8  8   8  8   8  8   8  8\n");
    printf("         8 8 8  88888   8 8   88888  8\n");
    printf("         8  88  8   8   8 8   8   8  8\n");
    printf("         8   8  8   8    8    8   8  88888\n\n");
    
    /*entrada de coordenadas dos navios humanos*/
    printf("Entre com as coordenadas de seus 6 navios (linha entre 0 e 9, coluna entre 0 e 7\n");
    for (cont=0; cont<6; cont++)
    {   do {    printf("Navio %d: ", cont+1);
                scanf("%d%d", &i,&j);
                if(i<0 || i>9 || j<0 || j>7) printf("Erro na coordenada. (Fora dos limites) Digite-a Novamente\n");
                else if(matHuman[i][j]==NAVIO || matHuman[i][j+1]==NAVIO || matHuman[i][j+2]==NAVIO) printf("Erro na coordenada. (Sobreposiçao de navios) Digite-a Novamente\n");
        }while(i<0 || i>9 || j<0 || j>7 || matHuman[i][j]==NAVIO || matHuman[i][j+1]==NAVIO || matHuman[i][j+2]==NAVIO);
        matHuman[i][j] = NAVIO;
        matHuman[i][j+1] = NAVIO; /*coluna seguinte*/
        matHuman[i][j+2] = NAVIO; /*coluna seguinte da seguinte*/
    }
    
    /*Imprimindo o tabuleiro do humano*/
    printf("\nImprimindo tabuleiro do humano:\n");
    printf("   0 1 2 3 4 5 6 7 8 9\n");
    for(i=0; i<10; i++)
    {   printf("%d |", i);
        for(j=0; j<10; j++)
        {   if(matHuman[i][j]==AGUA)printf(" |");
            else if(matHuman[i][j]==NAVIO)printf("N|");
            else if(matHuman[i][j]==TIRONAGUA)printf("A|");
            else if(matHuman[i][j]==TIRONAVIO)printf("X|");
        }
        printf("\n");
    }
    printf("\n");
    
    /*O jogo pode começar de fato agora*/
    printf("8888888  8888888  88   88  8888888  888888  8888888  8     8\n");
    printf("8        8     8  8 8 8 8  8        8       8     8  8     8\n");
    printf("8        8     8  8  8  8  8888888  8       8     8  8     8\n");
    printf("8        8     8  8  8  8  8        8       8     8  8     8\n");
    printf("8888888  8888888  8  8  8  8888888  888888  8888888  8888888\n\n");
    int pontosHuman = 0, pontosPC = 0;
    
    /*enquanto ninguém fez 18 pontos...*/
    while(pontosHuman<18 && pontosPC<18)
    {   bool coordenadaJaDigitada;
        /*leia a jogada do humano*/
        printf("Entre com as coordenadas do seu tiro (linha entre 0 e 9, coluna entre 0 e 7)\n");
        do {    printf("Tiro: ");
                scanf("%d%d", &i,&j);
                if(i<0 || i>9 || j<0 || j>9) printf("Erro na coordenada. (Fora dos limites) Digite-a Novamente\n");
                else if(matPc[i][j]==TIRONAVIO || matPc[i][j]== TIRONAGUA) printf("Erro na coordenada. (Disparo ja efetuado na coordenada) Digite-a Novamente\n");
            }while (i<0 || i>9 || j<0 || j>9 || matPc[i][j]==TIRONAVIO || matPc[i][j]== TIRONAGUA);
        if(matPc[i][j]==NAVIO) 
        {   matPc[i][j] = TIRONAVIO;
            printf("\nVoce acertou o tiro!\n");
            pontosHuman++;
        }
        else
        {   matPc[i][j] = TIRONAGUA;
            printf("\nVoce errou o tiro!\n");
        }
        
        
        /*atualizo o tabuleiro do computador*/
        printf("Imprimindo tabuleiro maquina:\n");
        printf("   0 1 2 3 4 5 6 7 8 9\n");
        for(i=0; i<10; i++)
        {   printf("%d |", i);
            for(j=0; j<10; j++)
            {   if(matPc[i][j]==AGUA)printf(" |");
                else if(matPc[i][j]==NAVIO)printf(" |");
                else if(matPc[i][j]==TIRONAGUA)printf("A|");
                else if(matPc[i][j]==TIRONAVIO)printf("X|");
            }
            printf("\n");
        }
        printf("\n");
        
        /*gero a jogada aleatoria do computador (sem estratégia)*/
        if(estrategia == false)
        {
            do {    i = rand()%10; /*linha vai de 0 a 9*/
                j = rand()%10; /*coluna vai de 0 a 9*/
            }while(matHuman[i][j]==TIRONAGUA || matHuman[i][j]==TIRONAVIO);
            if(matHuman[i][j]==NAVIO)
            {   matHuman[i][j] = TIRONAVIO;
                printf("Computador acertou!\n");
                pontosPC++;
                iAnterior = i;
                jAnterior = j;
                estrategia = true;
                partesNavioDerrubadas = 1;
            }
            else if(matHuman[i][j]==AGUA)
            {   matHuman[i][j] = TIRONAGUA;
                printf("O computador errou!\n");
            }
            
        }
        
        else /*jogada com estratégia*/
        {   i = iAnterior;
            j = jAnterior + 1;    
            
            if(matHuman[i][j] == TIRONAGUA) /*se já joguei na agua, volta 3 colunas invertendo o lado*/
            {   j = j - 3;  
            }
            
            if(matHuman[i][j] == AGUA) /*se é agua, atiro na agua e inverto o lado (-4 colunas)*/
            {   matHuman[i][j] = TIRONAGUA;
                printf("O computador atirou na agua...\n");
                jAnterior = j - 4;
            }
            else if(matHuman[i][j] == NAVIO) /*se é navio, acerto e continuo com os valores da coluna e linha*/
            {   matHuman[i][j] = TIRONAVIO;
                printf("O computador acertou!!!...\n");
                pontosPC++;
                iAnterior = i;
                jAnterior = j;
                partesNavioDerrubadas++;
                if(partesNavioDerrubadas == 3) /*atingi 3 partes, volto para o aleatório*/
                    estrategia = false;
            }
                
        }
        
        /*mostro o tabuleiros do humano*/
        printf("Imprimindo tabuleiro do humano:\n");
        printf("   0 1 2 3 4 5 6 7 8 9\n");
        for(i=0; i<10; i++)
        {   printf("%d |", i);
            for(j=0; j<10; j++)
            {   if(matHuman[i][j]==AGUA)printf(" |");
                else if(matHuman[i][j]==NAVIO)printf("N|");
                else if(matHuman[i][j]==TIRONAGUA)printf("A|");
                else if(matHuman[i][j]==TIRONAVIO)printf("X|");
            }
            printf("\n");
        }
        printf("\n");
        
        /*mostro o placar atualizado*/
        printf("PLACAR, Humano: %d Maquina: %d\n\n",pontosHuman,pontosPC);
    }
        
    /*mostra o vencedor*/
    if(pontosHuman == 18) printf("Voce ganhou!!! Parabens!!\n");
    else printf("Voce perdeu para o Computador!!! Patinho\n");
   
    return 0;
}
