
import javax.swing.JOptionPane;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Arthur
 */
public class Fibonacci {
    static long fibo(int n) {
        if (n < 2) {
            return n;
        } else {
            return fibo(n - 1) + fibo(n - 2);
        }
    }
    
    public static void main(String[] args) {
        int x;
        String A;
        
        
        
        try{
            A = JOptionPane.showInputDialog(null,"Digite o valor a ser mostrado pelo Fibonacci");
            x = Integer.parseInt(A);

            // teste do programa. Imprime os 30 primeiros termos
            for (int i = 0; i < x; i++) {
                System.out.print("(" + i + "):" + Fibonacci.fibo(i) + "\t");
            }

        }
        /*catch(ArithmeticException ex) {
            JOptionPane.showMessageDialog(null, "Voce tentou dividir por Zero! ","ERRO",1);
        }*/
        catch(NumberFormatException e){
            JOptionPane.showMessageDialog(null, "O dado tem que ser apenas numérico!","ERRO :",1);
        }
        System.exit(0);

    }
}
