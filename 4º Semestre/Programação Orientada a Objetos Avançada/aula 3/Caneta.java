package sab;

public class Caneta {
	//ATRIBUTOS
		private String cor;
		private double ponta;
		private int carga;
		private boolean tampada;
		
		//METODO CONSTRUTOR
		
		public Caneta(String x, double y)
		{
			this.tampada=true;
			this.carga=100;
			this.cor=x;
			this.ponta=y;
		}
		
		//METODOS
		public void escrever()
		{
			if(this.tampada==true)
				System.out.println("Erro!!Caneta esta tampada");
			else
				System.out.println("Escrevendo...");
		}
		
		public void tampar()
		{
			this.tampada=true;
		}
		
		public void destampar()
		{
			this.tampada=false;
		}

		public void estado()
		{
			System.out.println("Cor: "+this.cor);
			System.out.println("Ponta: "+this.ponta);
			System.out.println("Esta tampada? "+this.tampada);
			System.out.println("A carga atual e "+this.carga+"%");
		}

		
		
		//METODOS ACESSORES E MODIFICADORES
		public int getCarga() {
			return carga;
		}

		public void setCarga(int carga) {
			if(carga <0)
				this.carga = 0;
			else if (carga>100)
				this.carga = 100;
			else
				this.carga = carga;
		}
		
		
		
}
