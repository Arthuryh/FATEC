package sab;

public class Cliente implements Pessoa{
	 //ATRIBUTOS
    private String nome, genero;
    private int idade, cpf, energia;
    private boolean status;
    
    //METODO CONSTRUTOR
    public Cliente(String n, String g, int i, int cp, int e)
    {
        this.nome = n;
        this.genero = g;
        this.idade = i;
        this.cpf = cp;
        this.energia = e;
        this.status=false;
    
    }


   //METODOS
    
    public void estado()
    {
        System.out.println("\nNome: "+this.nome);
        System.out.println("Gênero: "+this.genero);
        System.out.println("Idade: "+this.idade);
        System.out.println("CPF: "+this.cpf);
        System.out.println("Status: "+this.status);
        System.out.println("Energia: "+this.energia);
        
    }
    
    
    public void status()
    {
        if(this.status==true)
            System.out.println("\nO cliente está cadastrado");
        
        else System.out.println("\nO cliente não está cadastrado");
    }
    
    public void cadastrar()
    {
        this.status=true;
    }

    //acessores, modificador

	public String getNome() {
		return nome;
	}


	public void setNome(String nome) {
		this.nome = nome;
	}


	public String getGenero() {
		return genero;
	}


	public void setGenero(String genero) {
		this.genero = genero;
	}


	public int getIdade() {
		return idade;
	}


	public void setIdade(int idade) {
		this.idade = idade;
	}


	public int getCpf() {
		return cpf;
	}


	public void setCpf(int cpf) {
		this.cpf = cpf;
	}


	public boolean isStatus() {
		return status;
	}


	public void setStatus(boolean status) {
		this.status = status;
	}

	//Metodos implementados da interface pessoa
	@Override
	public void andar() {
		if(this.energia<0)
			this.energia = 0;
		else
			this.energia-=5;
		
	}


	@Override
	public void correr() {
		if(this.energia<0)
			this.energia = 0;
		else
			this.energia-=10;
	}


	@Override
	public void falar() {
		System.out.println("A pessoa está falando...");
		
	}
    
    
}