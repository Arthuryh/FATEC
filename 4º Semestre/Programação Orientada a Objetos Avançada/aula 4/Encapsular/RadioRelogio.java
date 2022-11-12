package Encapsular;

public class RadioRelogio implements Radio, Relogio{
	private int hora;
	private int minuto;
	private boolean despertador, ligado;
	private int vol;
	
	
	@Override
	public void mudarHora() {
		if(this.hora>23)
			this.hora=0;
		else
			this.hora++;
	}

	@Override
	public void mudarMinuto() {
		if(this.minuto>59) {
			this.minuto=0;
			this.hora++;
		}
		else
			this.minuto++;
	}

	@Override
	public void despertar() {
		System.out.println("PAN...PAN...PAN...PAN...");
		
	}

	@Override
	public void ligar() {
		if(this.ligado==true) 
			System.out.println("Já está ligado...");
		else {
			this.ligado=true;
			this.vol=30;
			this.hora=0;
			this.minuto=0;
			
		}
	}

	@Override
	public void desligar() {
		this.ligado = false;
	}

	@Override
	public void maisVol() {
		this.vol++;
	}

	@Override
	public void menosVol() {
		this.vol--;
	}

	@Override
	public void trocaEstacao() {
		System.out.println("Trocando de estação...");
	}
	
}
