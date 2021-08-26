//FATEC Ipiranga
//Disciplina: Programacao Estruturada e Modular
//Aluno.....: Arthur Yoshio Hayakawa

#include <stdio.h>
#include <locale.h>

int main()
{   setlocale(LC_ALL, "Portuguese");
	
	int aux1 = 0, aux2 = 0, i, soma, tamanho1, tamanho2, casas;
    
	//----PRIMEIRO VETOR----
    printf("Quantas casas o 1o numero possui? ");
    scanf("%d", &tamanho1); //o tamanho1, vai servir de paramatro para definir o tamanho dos vetores
    
    int vet1[tamanho1+1], //o primeiro vetor, tem um espa�o adicional, se houver necessidade de exibir um n�mero proveniente das somas
	vet2[tamanho1]; //o segundo vetor, recebe o mesmo tamanho do tamanho1, caso tenha n�meros de mesmo tamanho, ou que seja um numero menor
    
	for(i=0; i<tamanho1+1; i++) { //preenchimento do 1o vetor de 0,
		vet1[i] = 0; }			  // evitando sujeiras de memoria e possiveis problemas
    	
    for(i=1; i<=tamanho1; i++) { //preenchimento do vetor com n�meros escolhidos pelo usu�rio
    	printf("Qual o numero da %d1o casa? [digite de 0 a 9] ",i);
    	scanf("%d",&aux1);
    	vet1[i-1] = aux1; }
	
	printf("O numero digitado foi: "); //exibicao dos numeros digitados
	for(i=tamanho1; i>0; i--) {
		printf("%d",vet1[i-1]); }
	
	//----SEGUNDO VETOR----
	printf("\n\nQuantas casas o 2o numero possui? [Deve ser menor ou igual que o N de casas do 1o Numero] ");	//definicao do tamanho2, na qual vai servir de parametro para
    scanf("%d", &tamanho2);																						//saber quantos espacos preencher no 2o vetor, e realizar os
    																											//futuros calculos
    for(i=0; i<tamanho1; i++) { //preenchendo os espa�os do 2� vetor com 0,
    	vet2[i] = 0;	}		//evitando sujeiras de mem�ria e poss�veis problemas
    
	for(i=1; i<=tamanho2; i++) { //preenchimento do vetor com n�meros escolhidos pelo usu�rio
    	printf("Qual o numero da %d1a casa? [digite de 0 a 9] ",i);
    	scanf("%d",&aux1);
    	vet2[i-1] = aux1; }
	
	printf("O numero digitado foi: "); //exibi��o dos n�meros digitados
	for(i=tamanho2; i>0; i--) {
		printf("%d",vet2[i-1]); }
	
	//----EXIBICAO DO 1o VETOR ANTES DO CALCULO----
	printf("\n\n\nREALIZACAO DO CALCULO: ");
	printf("\n1aSeq: ");
	for(i=tamanho1; i>0; i--) {
		printf("%d",vet1[i-1]); }	
		
	//----PARTE DO CALCULO----
	casas = 0;
	for(i=1; i<=tamanho2; i++) { //loop que realiza os calculos de acordo com o tamanho de casas que ha no segundo vetor
		soma = vet1[casas] + vet2[casas];
	    aux1 = soma/10; //calcula o valor para a pr�xima casa
	    aux2 = soma%10; //calcula o numero da casa atual
		vet1[casas] = aux2;	//define que a respectiva casa, vai receber o valor da soma efetuada entre os espacos dos vetores
		
		if(aux1 >=1) { //se do c�lculo para o valor da pr�xima casa tiver um n�mero maior ou igual que 1, soma esse 1 para o n�mero que houver na pr�xima casa
	    	vet1[casas+1] = vet1[casas+1] + aux1;	}
	    	casas++;	}
	
	//----EXIBICAO DO 2o VETOR----
	printf("\n2aSeq: ");
	for(i=tamanho2; i>0; i--) {
		printf("%d",vet2[i-1]); }	

	//----EXIBICAO DO RESULTADO----
	printf("\n---------------\n"); 
	for(i=tamanho1; i>=0; i--) { 	//OBSERVASAO: EM CASOS ESPECIFICOS, E EXIBIDO UM 0 ADICIONAL AO RESULTADO, ISSO ACONTECE POR CAUSA DA CASA ADICIONAL
		printf("%d ", vet1[i]);	   	//DEDICADA PARA UM NUMERO PROVENIENTE DA SOMA DA CASA ANTERIOR, NAO E UM ERRO, E SIM UMA PRECAUCAO
		casas--;	}
		
	return 0;	}
