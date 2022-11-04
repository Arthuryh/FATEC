package exercicio1;

import java.util.Scanner;

public class ex1 {
	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		
		double p, e, m;
		
		System.out.print("Digite o peso dos tomates: ");
		p = ler.nextDouble();
		
		if(p > 50) {
			e = p - 50;
			m = e * 4.00;
			
			System.out.println("\nPeso dos tomates: " + p + "kg");
			System.out.println("Peso excedente: " + e + "kg");
			System.out.println("Valor Multa: R$" + m);
		}
		
		else {
			e = 0;
			m = 0;
			
			System.out.println("\nPeso dos tomates: " + p + "kg");
			System.out.println("Peso excedente: " + e + "kg");
			System.out.println("Valor Multa: R$" + m);
		}
	}
}
