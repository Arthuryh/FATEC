
import javax.swing.JOptionPane;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Arthur
 */
public class limiteSuperior {
    public static void main(String[] args) {
        // TODO code application logic here
        
        int x,y,j;
        String A = "";
        
        try{
            A = JOptionPane.showInputDialog(null, "Digite o limite superior");
            x = Integer.parseInt(A);
            
            A = JOptionPane.showInputDialog(null, "Digite o incremento");
            y = Integer.parseInt(A)-1;
            
            for (j=0; j<=x; j++){
            System.out.println(""+j);
            j = j+y;
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
