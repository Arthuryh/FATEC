package introducao;

import java.util.Scanner;

/*



*/
public class DecisaoIf {

	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		int x;
		
		System.out.print("Digite um numero: ");
		x = ler.nextInt();
		
		if(x > 5 && x%2==0) System.out.println("O valor e maior que 5 e par");
		else if(x>5 && x%2!=0) System.out.println("O valor e maior que 5 e impar");
		else if(x<5 && x%2==0) System.out.println("O valor é menor que 5 e par");
		else if(x<5 && x%2!=0) System.out.println("O valor é menor que 5 e impar");
		else System.out.println("O valor e 5");
		
		System.out.println("FIM DO PROGRAMA");
	}

}
