/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */

/**
 *
 * @author Arthur
 */

import javax.swing.*;
public class Exemplo_throw {

    /**
     * @param args the command line arguments
     */
    public static void efetuar(){
        int x = 12, y=0,c=0;
        
        try{
            String B = JOptionPane.showInputDialog(null,"Digite o valor de Y");
            y = Integer.parseInt(B);
            
            if(x/y==1) {
                throw new Exception("Nova_Exceção");
            }
            c = x/y;
            JOptionPane.showMessageDialog(null, "A parte inteira do resultado e "+c,"Resultado",1);
        }
        catch(NumberFormatException e){
            JOptionPane.showMessageDialog(null,"Digite apenas números !","ERRO",1);
            efetuar();
        }
        catch(ArithmeticException e){
            JOptionPane.showMessageDialog(null, "Proibido dividir por Zero !","ERRO",1);
            efetuar();
        }
        catch(Exception Nova_Exceção){
            JOptionPane.showMessageDialog(null, "Valores entre 7 e 12 são proibidos !","ERRO",1);
            efetuar();
        }
        System.exit(0);
    }
    
    public static void main(String[] args) {
        efetuar();
        
    }
    
}
