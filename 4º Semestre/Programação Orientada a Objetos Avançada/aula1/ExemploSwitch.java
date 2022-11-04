package introducao;

import java.util.Scanner;

public class ExemploSwitch {

	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		
		int n1,n2, calc=0, op;
		
		System.out.println("Digite o primeiro numero: ");
		n1 = ler.nextInt();
				
		System.out.println("Digite o segundo numero: ");
		n2 = ler.nextInt();
		
		System.out.println("\nDigite:\n1-Soma\n2-Subtracao\n3-Divisao\n4-Multiplicacao");
		op=ler.nextInt();
		
		switch(op) {
			case 1: {
				calc= n1+n2;
				System.out.println("A soma e igual a: " + calc);
				break;
			}
			
			case 2: {
				calc = n1-n2;
				System.out.println("A subtracao e igual a: " + calc);
				break;
			}
		
			case 3: {
				if(n2==0) {
					System.out.println("ERRO!!! Nao dividiras por 0");
				}
				else {
					calc = n1/n2;
					System.out.println("A divisao e igual a: " + calc);
				}
				break;
			}
			
			case 4: {
				calc = n1*n2;
				System.out.println("A multiplicacao e igual a: " + calc);
				break;
			}
			
			default: {
				System.out.println("Opcao invalida!!!");
			}
			
			System.out.println("FIM DO PROGRAMA!");
		}
	}
}