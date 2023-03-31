/*
 * Nome: Igor Ribeiro Ferreira de Matos
 * RA: 140492
 * <= Professor, como n�o iremos fazer conex�es com bancos de dados, e fazer card�pios est�ticos seria muito trabalhoso, 
 * eu meramente simulei as implementa��es de consultas, inser��es e afins, espero que isto n�o seja um problema significante =>
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
		//perguntar qual o n�mero de telefone da pessoa
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
			//j� t� cadastrada
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
