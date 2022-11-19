package Polimorfismo;

public class Calcular {
	public void divisao(double n1, double n2) {
		double divisao = n1/n2;
		
		if(n2==0) System.out.println("Divisão inválida");
		else System.out.println("Resultado da divisão: " + divisao); 
	}
	
	public void resultado(int n1, int n2) {
		int divisao = n1%n2;
		
		System.out.println("Resultado da divisão: " + divisao);
	}
	
	public void concatenar(String t1, String t2) {
		System.out.println(t1+" " +t2);
	}	
}

