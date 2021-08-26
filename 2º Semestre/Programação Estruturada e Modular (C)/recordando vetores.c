//FATEC Ipiranga
//Disciplina: Programa��o Estruturada e Modular
//Aluno.....: Arthur Yoshio Hayakawa

#include <stdio.h>
#include <locale.h>

int main()
{   setlocale(LC_ALL, "Portuguese");
	
	int aux1 = 0, aux2 = 0, i, soma, tamanho1, tamanho2, casas;
    
	//----PRIMEIRO VETOR----
    printf("Quantas casas o 1� n�mero possu�? ");
    scanf("%d", &tamanho1); //o tamanho1, vai servir de param�tro para definir o tamanho dos vetores
    
    int vet1[tamanho1+1], //o primeiro vetor, tem um espa�o adicional, se houver necessidade de exibir um n�mero proveniente das somas
	vet2[tamanho1]; //o segundo vetor, recebe o mesmo tamanho do tamanho1, caso tenha n�meros de mesmo tamanho, ou que seja um numero menor
    
	for(i=0; i<tamanho1+1; i++) { //preenchimento do 1� vetor de 0,
		vet1[i] = 0; }			  // evitando sujeiras de mem�ria e poss�veis problemas
    	
    for(i=1; i<=tamanho1; i++) { //preenchimento do vetor com n�meros escolhidos pelo usu�rio
    	printf("Qual o n�mero da %d� casa? [digite de 0 a 9] ",i);
    	scanf("%d",&aux1);
    	vet1[i-1] = aux1; }
	
	printf("O n�mero digitado foi: "); //exibi��o dos n�meros digitados
	for(i=tamanho1; i>0; i--) {
		printf("%d",vet1[i-1]); }
	
	//----SEGUNDO VETOR----
	printf("\n\nQuantas casas o 2� n�mero possu�? [Deve ser menor ou igual que o n� de casas do 1� N�mero] ");	//defini��o do tamanho2, na qual vai servir de par�metro para
    scanf("%d", &tamanho2);																						//saber quantos espa�os preencher no 2� vetor, e realizar os
    																											//futuros calculos
    for(i=0; i<tamanho1; i++) { //preenchendo os espa�os do 2� vetor com 0,
    	vet2[i] = 0;	}		//evitando sujeiras de mem�ria e poss�veis problemas
    
	for(i=1; i<=tamanho2; i++) { //preenchimento do vetor com n�meros escolhidos pelo usu�rio
    	printf("Qual o n�mero da %d� casa? [digite de 0 a 9] ",i);
    	scanf("%d",&aux1);
    	vet2[i-1] = aux1; }
	
	printf("O n�mero digitado foi: "); //exibi��o dos n�meros digitados
	for(i=tamanho2; i>0; i--) {
		printf("%d",vet2[i-1]); }
	
	//----EXIBI��O DO 1�VETOR ANTES DO CALCULO----
	printf("\n\n\nREALIZA��O DO CALCULO: ");
	printf("\n1�Seq: ");
	for(i=tamanho1; i>0; i--) {
		printf("%d",vet1[i-1]); }	
		
	//----PARTE DO CALCULO----
	casas = 0;
	for(i=1; i<=tamanho2; i++) { //loop que realiza os calculos de acordo com o tamanho de casas que h� no segundo vetor
		soma = vet1[casas] + vet2[casas];
	    aux1 = soma/10; //calcula o valor para a pr�xima casa
	    aux2 = soma%10; //calcula o numero da casa atual
		vet1[casas] = aux2;	//define que a respectiva casa, vai receber o valor da soma efetuada entre os espa�os dos vetores
		
		if(aux1 >=1) { //se do c�lculo para o valor da pr�xima casa tiver um n�mero maior ou igual que 1, soma esse 1 para o n�mero que houver na pr�xima casa
	    	vet1[casas+1] = vet1[casas+1] + aux1;	}
	    	casas++;	}
	
	//----EXIBI��O DO 2� VETOR----
	printf("\n2�Seq: ");
	for(i=tamanho2; i>0; i--) {
		printf("%d",vet2[i-1]); }	

	//----EXIBI��O DO RESULTADO----
	printf("\n---------------\n"); 
	for(i=tamanho1; i>=0; i--) { 	//OBSERVA��O: EM CASOS ESPEC�FICOS, � EXIBIDO UM 0 ADICIONAL AO RESULTADO, ISSO ACONTECE POR CAUSA DA CASA ADICIONAL
		printf("%d ", vet1[i]);	   	//DEDICADA PARA UM N�MERO PROVENIENTE DA SOMA DA CASA ANTERIOR, N�O � UM ERRO, E SIM UMA PRECAU��O
		casas--;	}
		
	return 0;	}
