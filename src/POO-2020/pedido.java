/*
 * Nome: Igor Ribeiro Ferreira de Matos
 * RA: 140492
 * <= Professor, como não iremos fazer conexões com bancos de dados, e fazer cardápios estáticos seria muito trabalhoso, 
 * eu meramente simulei as implementações de consultas, inserções e afins, espero que isto não seja um problema significante =>
 * */
package diskPizza;

public class pedido { 
 
  	public static void main(String[] args) {
  		//registrando distribuidora de bebidas
  		distribuidora dist = new distribuidora();
  		String cgc = "xxx", contato="yyy", inscEst="ss", inscMun="pp", distNome="aabb", tel="xx xxxx-xxxx";
  		
  		dist.setCGC(cgc);
  		dist.setContato(contato);
  		dist.setInscEst(inscEst);
  		dist.setInscMun(inscMun);
  		dist.setNome(distNome);
  		dist.setTel(tel);
  		
  		dist.cadastro();
  		
  		dist.adicionar("coca-cola", 5);
  		
  		
		cadastroPessoa pessoa = new cadastroPessoa();
		//perguntar qual o número de telefone da pessoa
		String telefone = "129000000";
		
		
		if(pessoa.verifica(telefone) == true) {
			//realiza o cadastro da pessoa
			String nome, endereco, cpf;
			System.out.println("Cadastrando pessoa...");
			nome = "Igor";
			endereco = "Edgar pereira de campos, 323";
			cpf = "33333333333";
			
			pessoa.setCpf(cpf);
			pessoa.setEndereco(endereco);
			pessoa.setNome(nome);
			pessoa.setTelefone(telefone);
			
			pessoa.cadastro();
			
		}else {
			//já tá cadastrada
		}
		
		pizzaPedido p1 = new pizzaPedido();
		p1.setEndereco(pessoa.getEndereco());
		p1.setTelefone(pessoa.getTelefone());
		
		//adicionar as pizzas a serem pedidas
		p1.adicionar("mussarela", "quatro queijos", "frango c/ catupiry");
		p1.adicionarBebida("coca-cola", 2, dist);
		p1.finalizar();
		
	}

}
