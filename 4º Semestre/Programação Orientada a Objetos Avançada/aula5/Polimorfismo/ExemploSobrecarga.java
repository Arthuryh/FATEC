package Polimorfismo;

public class ExemploSobrecarga {

	public static void main(String[] args) {
		Sobrecarga s = new Sobrecarga();
		Calcular c = new Calcular();
		
		s.soma();
		s.soma(20);
		s.soma(3.14, 2.75);
		s.soma(7, 6);
		s.soma("concatenar", "teste");
		
		c.divisao(5.0, 2.0);
		c.resultado(10, 5);
		c.concatenar("Teste", "Sobrecarga");
	}

}
