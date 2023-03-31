package diskPizza;

public class cadastroPessoa {
	String nome, endereco, telefone, cpf;
	
	public String getNome() {
		return nome;
	}

	public String getEndereco() {
		return endereco;
	}

	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getTelefone() {
		return telefone;
	}

	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}

	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		this.cpf = cpf;
	}

	public boolean verifica(String telefone) {
		System.out.println("\nVerificando se o telefone informado consta no banco de dados...\n");
		/*
		 * se sim -> retornar falso
		 * se não -> retornar true
		 * */
		return true;
	}
	
	public void cadastro() {
		//implementação de banco de dados
		System.out.println("Cadastro efetuado. Dados inseridos no banco de dados: " + this.nome + " " + this.cpf + " " +this.endereco + " " + this.telefone);
	}
	

}
