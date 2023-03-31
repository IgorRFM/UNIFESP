package heranca;

public class Banco {

	public static void main(String[] args) {
		
		conta[] c0 = new conta[3]; 
		
		c0[0] = new contaCorrente(1);
		c0[1] = new contaPoupanca(2);
		c0[2] = new conta(3);
		
		contaCorrente cc = (contaCorrente) c0[0];
		contaPoupanca cp = (contaPoupanca) c0[1];
		conta c = c0[2];
		
		cc.setLimite(500); //definindo o limite de 500 reais
		cc.imprime();
		cc.creditaCC(550); //tentando sacar mais dinheiro do que tem no saldo+limite
		cc.imprime();
		cc.creditaCC(150); //tentando sacar um valor aceitável
		cc.imprime();
		
		System.out.println("\n_______________\n");
		
		cp.setJuros(0.11); //juros de 0,11% ao mês
		cp.debita(1000); //adicionando 1000 reais ao saldo, para testar o juros
		cp.imprime();
		cp.atualiza();
		cp.atualiza();
		
		System.out.println("\n_______________\n");
		
		c.debita(300);
		c.imprime();
		
		
	}

}
