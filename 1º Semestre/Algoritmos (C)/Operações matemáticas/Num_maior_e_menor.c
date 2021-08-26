int main()
{
    int n,i,vz,maior,menor;
    i = 1;
    
    printf("Digite quantas vezes verificar:");
    scanf("%d",&vz);
    
    printf("Digite o %d numero:",i);
    scanf("%d",&n);
    maior = n;
    menor = n;
    
    for(i=2;i<=vz; i++){
        printf("Digite o %d numero:",i);
        scanf("%d",&n);
        if(n > maior) {
            maior = n;
        }
        else if (n < menor) {
            menor = n;
        }
    }
    
    printf("O menor numero foi %d e o maior %d",menor,maior);
   

    return 0;
}
