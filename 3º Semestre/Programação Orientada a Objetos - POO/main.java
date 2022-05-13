import javax.swing.JOptionPane;
public class main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int num, nPrimo;
        num = Integer.parseInt(JOptionPane.showInputDialog(null,"Digite um numero: ","Primo",JOptionPane.QUESTION_MESSAGE));
        
        nPrimo = primo(num);
        
        if(nPrimo == 0) {
            JOptionPane.showMessageDialog(null, "O número "+ num + " não é um numero primo", "Não é Primo",JOptionPane.QUESTION_MESSAGE);
        }
        else {
            JOptionPane.showMessageDialog(null, "O número "+ num + " é um número primo", "É Primo",JOptionPane.QUESTION_MESSAGE);
        }
        
    }
    public static int primo(int x) {
        for(int j = 2; j < x; j++) {
            if (x % j == 0) return 0;
        }
        return 1; 
    }
}