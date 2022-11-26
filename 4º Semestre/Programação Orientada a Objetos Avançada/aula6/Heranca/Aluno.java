package Heranca;

public class Aluno extends Pessoa{
	private int ra;
	private String curso;
	
	public void entregaAtividade() {
		System.out.println("Atividade entregue com sucesso");
	}

	public int getRa() {
		return ra;
	}

	public void setRa(int ra) {
		this.ra = ra;
	}

	public String getCurso() {
		return curso;
	}

	public void setCurso(String curso) {
		this.curso = curso;
	}
}
