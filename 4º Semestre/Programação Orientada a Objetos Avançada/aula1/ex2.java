package exercicio1;

import java.util.Scanner;

public class ex2 {

	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		
		double c, n, e=0;
		
		System.out.print("Digite o codigo do operario: ");
		c = ler.nextDouble();
		
		System.out.print("\nDigite o numero de horas trabalhadas: ");
		n = ler.nextDouble();
		
		if(n > 50) {
			e = n - 50;
			
			System.out.println("\nHoras Trabalhadas: " + n + "hrs");
			System.out.println("Salario total: R$" + (n-e)*10);
			System.out.println("Salario excedente: R$" + e*20);
		}
		
		else {
			System.out.println("\nHoras Trabalhadas: " + n + "hrs");
			System.out.println("Salario total: R$" + n*10);
		}
		

	}

}
