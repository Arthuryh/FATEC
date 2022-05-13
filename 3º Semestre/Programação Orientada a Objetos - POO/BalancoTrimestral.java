
class BalancoTrimestral {

    public static void main(String [] args){
        int gastosjaneiro = 15000;
        int gastosFevereiro = 23000;
        int gastosMarco = 17000;
        int gastosTrimestre = gastosjaneiro + gastosFevereiro + gastosMarco;
        
        System.out.println("Gasto do trimestre: R$" + gastosTrimestre);
        int mediaPorMes = gastosTrimestre / 3;
        System.out.println("Média mensal: R$" + mediaPorMes);
    }
}