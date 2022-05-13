/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */

/**
 *
 * @author Arthur
 */
import javax.swing.*;

public class Exemplo_Try_Catch {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int x = 0, y = 0, c = 0;
        
        String A = "", B = "";
        
        try{
            A = JOptionPane.showInputDialog(null,"Digite o valor de X");
            x = Integer.parseInt(A);
            
            B = JOptionPane.showInputDialog(null,"Digite o valor de Y");
            y = Integer.parseInt(B);
            
            c = x/y;
            JOptionPane.showMessageDialog(null, "A parte inteira do resultado e "+c,"RESULTADO",1);
        }
        catch(ArithmeticException ex) {
            JOptionPane.showMessageDialog(null, "Voce tentou dividir por Zero! ","ERRO",1);
        }
        catch(NumberFormatException e){
            JOptionPane.showMessageDialog(null, "O dado tem que ser apenas numérico!","ERRO :",1);
        }
        System.exit(0);
    }
    
}
