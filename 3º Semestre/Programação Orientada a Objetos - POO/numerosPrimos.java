
import javax.swing.JOptionPane;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */

/**
 *
 * @author Arthur
 */
public class numerosPrimos {

    public static void main(String[] args) {
        int x = 0;

        String A = "";

        try {
            A = JOptionPane.showInputDialog(null, "Digite o valor a ser dito se é primo ou não");
            x = Integer.parseInt(A);

            for (int i = 2; i <= x; i++) {
                if (ehPrimo(i)) {
                    System.out.println(i + " eh primo.");
                }
            }
        } /*catch(ArithmeticException ex) {
            JOptionPane.showMessageDialog(null, "Voce tentou dividir por Zero! ","ERRO",1);
        }*/ catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "O dado tem que ser apenas numérico!", "ERRO :", 1);
        }
        System.exit(0);
    }   
    
    private static boolean ehPrimo(int numero) {
        for (int j = 2; j < numero; j++) {
            if (numero % j == 0) {
                return false;
            }
        }
        return true;
    }
}
