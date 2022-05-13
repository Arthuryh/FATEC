
import javax.swing.JOptionPane;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Arthur
 */
public class notaBimestre {

    public static void main(String[] args) {
        int n1,n2,n3,n4,n5,n6,x;

        String A = "";

        try {
            
            A = JOptionPane.showInputDialog(null, "Digite a nota do 1º Bimestre");
            n1 = Integer.parseInt(A);
            
            A = JOptionPane.showInputDialog(null, "Digite a nota do 2º Bimestre");
            n2 = Integer.parseInt(A);
            
            A = JOptionPane.showInputDialog(null, "Digite a nota do 3º Bimestre");
            n3 = Integer.parseInt(A);
            
            A = JOptionPane.showInputDialog(null, "Digite a nota do 4º Bimestre");
            n4 = Integer.parseInt(A);
            
            A = JOptionPane.showInputDialog(null, "Digite a nota do 5º Bimestre");
            n5 = Integer.parseInt(A);
            
            A = JOptionPane.showInputDialog(null, "Digite a nota do 6º Bimestre");
            n6 = Integer.parseInt(A);
            
            x=(n1+n2+n3+n4+n5+n6)/6;
            
            JOptionPane.showMessageDialog(null, "A nota final desse aluno é: " + x,"Nota Final",JOptionPane.INFORMATION_MESSAGE);
        } /*catch(ArithmeticException ex) {
            JOptionPane.showMessageDialog(null, "Voce tentou dividir por Zero! ","ERRO",1);
        }*/ catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "O dado tem que ser apenas numérico!", "ERRO :", 1);
        }
        System.exit(0);
    }
}
