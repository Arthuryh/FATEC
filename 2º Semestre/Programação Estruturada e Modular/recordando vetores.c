//FATEC Ipiranga
//Disciplina: Programação Estruturada e Modular
//Aluno.....: Arthur Yoshio Hayakawa

#include <stdio.h>
#include <locale.h>

int main()
{   setlocale(LC_ALL, "Portuguese");
	
	int aux1 = 0, aux2 = 0, i, soma, tamanho1, tamanho2, casas;
    
	//----PRIMEIRO VETOR----
    printf("Quantas casas o 1º número possuí? ");
    scanf("%d", &tamanho1); //o tamanho1, vai servir de paramêtro para definir o tamanho dos vetores
    
    int vet1[tamanho1+1], //o primeiro vetor, tem um espaço adicional, se houver necessidade de exibir um número proveniente das somas
	vet2[tamanho1]; //o segundo vetor, recebe o mesmo tamanho do tamanho1, caso tenha números de mesmo tamanho, ou que seja um numero menor
    
	for(i=0; i<tamanho1+1; i++) { //preenchimento do 1º vetor de 0,
		vet1[i] = 0; }			  // evitando sujeiras de memória e possíveis problemas
    	
    for(i=1; i<=tamanho1; i++) { //preenchimento do vetor com números escolhidos pelo usuário
    	printf("Qual o número da %dº casa? [digite de 0 a 9] ",i);
    	scanf("%d",&aux1);
    	vet1[i-1] = aux1; }
	
	printf("O número digitado foi: "); //exibição dos números digitados
	for(i=tamanho1; i>0; i--) {
		printf("%d",vet1[i-1]); }
	
	//----SEGUNDO VETOR----
	printf("\n\nQuantas casas o 2º número possuí? [Deve ser menor ou igual que o nº de casas do 1º Número] ");	//definição do tamanho2, na qual vai servir de parâmetro para
    scanf("%d", &tamanho2);																						//saber quantos espaços preencher no 2º vetor, e realizar os
    																											//futuros calculos
    for(i=0; i<tamanho1; i++) { //preenchendo os espaços do 2º vetor com 0,
    	vet2[i] = 0;	}		//evitando sujeiras de memória e possíveis problemas
    
	for(i=1; i<=tamanho2; i++) { //preenchimento do vetor com números escolhidos pelo usuário
    	printf("Qual o número da %dº casa? [digite de 0 a 9] ",i);
    	scanf("%d",&aux1);
    	vet2[i-1] = aux1; }
	
	printf("O número digitado foi: "); //exibição dos números digitados
	for(i=tamanho2; i>0; i--) {
		printf("%d",vet2[i-1]); }
	
	//----EXIBIÇÃO DO 1ºVETOR ANTES DO CALCULO----
	printf("\n\n\nREALIZAÇÃO DO CALCULO: ");
	printf("\n1ºSeq: ");
	for(i=tamanho1; i>0; i--) {
		printf("%d",vet1[i-1]); }	
		
	//----PARTE DO CALCULO----
	casas = 0;
	for(i=1; i<=tamanho2; i++) { //loop que realiza os calculos de acordo com o tamanho de casas que há no segundo vetor
		soma = vet1[casas] + vet2[casas];
	    aux1 = soma/10; //calcula o valor para a próxima casa
	    aux2 = soma%10; //calcula o numero da casa atual
		vet1[casas] = aux2;	//define que a respectiva casa, vai receber o valor da soma efetuada entre os espaços dos vetores
		
		if(aux1 >=1) { //se do cálculo para o valor da próxima casa tiver um número maior ou igual que 1, soma esse 1 para o número que houver na próxima casa
	    	vet1[casas+1] = vet1[casas+1] + aux1;	}
	    	casas++;	}
	
	//----EXIBIÇÃO DO 2º VETOR----
	printf("\n2ºSeq: ");
	for(i=tamanho2; i>0; i--) {
		printf("%d",vet2[i-1]); }	

	//----EXIBIÇÃO DO RESULTADO----
	printf("\n---------------\n"); 
	for(i=tamanho1; i>=0; i--) { 	//OBSERVAÇÃO: EM CASOS ESPECÍFICOS, É EXIBIDO UM 0 ADICIONAL AO RESULTADO, ISSO ACONTECE POR CAUSA DA CASA ADICIONAL
		printf("%d ", vet1[i]);	   	//DEDICADA PARA UM NÚMERO PROVENIENTE DA SOMA DA CASA ANTERIOR, NÃO É UM ERRO, E SIM UMA PRECAUÇÃO
		casas--;	}
		
	return 0;	}
