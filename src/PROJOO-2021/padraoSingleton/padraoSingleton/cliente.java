package padraoSingleton;

public class cliente{
	private String nome;
	private int ID;
	
	public void novoCliente(String nome, int id) {
		this.nome = nome;
		this.ID = id;
	}

	protected String getNome() {
		return nome;
	}

	protected void setNome(String nome) {
		this.nome = nome;
	}

	protected int getID() {
		return ID;
	}

	protected void setID(int iD) {
		ID = iD;
	}

}
