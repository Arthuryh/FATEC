/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */

/**
 *
 * @author Arthur
 */
import javax.swing.*;
public class Exemplo_Try_Catch_Finally {
    static double compr=0, larg=0, prof=0, volume;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        try{
            String A = JOptionPane.showInputDialog(null,"Digite o comprimento");
            A = A.replace(',','.');
            compr = Double.parseDouble(A);
            
            String B = JOptionPane.showInputDialog(null,"Digite a largura");
            B = B.replace(',','.');
            larg = Double.parseDouble(B);
            
            String C = JOptionPane.showInputDialog(null,"Digite a profundidade");
            C = C.replace(',','.');
            prof = Double.parseDouble(C);
        }
        catch(NumberFormatException e){
            JOptionPane.showMessageDialog(null, "Digite apenas numeros","Volume da Piscina",1);
            System.exit(0);
        }
        finally{
            volume = (compr*larg*prof)*1000;
            volume *= 100;
            volume = Math.ceil(volume);
            volume /= 100;
            
            String st = "Para a piscina solicitada  "+
                        "\nAs dimensões são: "+compr+" X "+
                        " "+larg+" X "+prof+" (em metros)"+
                        "\n"+"\nO volume desta piscina = :"+volume+" litros";
            JOptionPane.showMessageDialog(null,st,"Volume da Piscina",1);
            System.exit(0);
        }
    }
    
}
