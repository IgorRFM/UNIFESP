package diskPizza;

public class pizzaPedido {
	String telefone, endereco, pedidoTotal="";
	int preco, qtde_pizzas=0, qtde_bebidas=0;

	public String getTelefone() {
		return telefone;
	}

	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}

	public String getEndereco() {
		return endereco;
	}

	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}

	public String getPedidoTotal() {
		return pedidoTotal;
	}

	public void setPedidoTotal(String pedidoTotal) {
		this.pedidoTotal = pedidoTotal;
	}
	
	public void adicionar(String ...args) {
		for (String param : args) {
			this.pedidoTotal += param + ", "; 
			System.out.println(param); 
			this.qtde_pizzas++;
		}
	}
	
	public void adicionarBebida (String nome, int qtde, distribuidora dist) {
		this.pedidoTotal += nome;
		this.qtde_bebidas = qtde;
		dist.remover(nome, qtde);
	}
	
	public void finalizar() {
		System.out.println("Finalizando pedido...");
		this.preco = this.qtde_pizzas * 20; //cada pizza 20 reais, supostamente, enquanto não tem como verificar num banco de dados
		this.preco += this.qtde_bebidas * 5; //cada refrigerante 5 reais,,
		 System.out.println("Seu pedido de: " + this.pedidoTotal + "\nTotalizou R$" + preco + ",00");
	}

}
