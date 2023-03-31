package ex3_1;

//folha
public class individuo extends Congresso{
	private String nome;
	private String assento;
	
	public individuo(String nome, String assento) {
		this.nome = nome;
		this.assento = assento;
	}

	@Override
	protected void Exibir() {
		System.out.println("Nome: " + this.nome + " | Assento: " + this.assento + "\n");
	}
	@Override
	protected int totalParticipantes() {
		return 1;
	}
	@Override
	protected int totalAssentos() {
		return 1;
	}
	
}
