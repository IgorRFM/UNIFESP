package diskPizza;

public class distribuidora {
	String nome, contato, CGC, inscEst, inscMun, tel;

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getContato() {
		return contato;
	}

	public void setContato(String contato) {
		this.contato = contato;
	}

	public String getCGC() {
		return CGC;
	}

	public void setCGC(String cGC) {
		CGC = cGC;
	}

	public String getInscEst() {
		return inscEst;
	}

	public void setInscEst(String inscEst) {
		this.inscEst = inscEst;
	}

	public String getInscMun() {
		return inscMun;
	}

	public void setInscMun(String inscMun) {
		this.inscMun = inscMun;
	}

	public String getTel() {
		return tel;
	}

	public void setTel(String tel) {
		this.tel = tel;
	}
	
	public void cadastro() {
		//implementação de banco de dados
		System.out.println("Cadastro de distribuidora de bebidas efetuado. Dados inseridos no banco de dados: " + this.CGC + " " + this.contato+ " " + this.inscEst + " " + this.inscMun + " " + this.nome + " " + this.tel);
	}

	public void adicionar(String nome, int qtde) {
		//inserir bebibas no banco de dados
		System.out.println("Adicionando " + qtde + " " + nome + "no banco de dados");
	}
	
	public void remover(String nome, int qtde) {
		//inserir bebibas no banco de dados
		System.out.println("removendo" + qtde + " " + nome + "no banco de dados");
	}
}
