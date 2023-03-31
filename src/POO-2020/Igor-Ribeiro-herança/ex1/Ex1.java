package heranca;

public class Ex1 {

	public static void main(String[] args) {
		contaCorrente cc = new contaCorrente(001);
		contaPoupanca cp = new contaPoupanca(002);
		
		cc.setLimite(500); //definindo o limite de 500 reais
		cc.imprime();
		cc.credita(550); //tentando sacar mais dinheiro do que tem no saldo+limite
		cc.imprime();
		cc.credita(150); //tentando sacar um valor aceitável
		cc.imprime();
		System.out.println("\n_______________\n");
		cp.setJuros(0.11); //juros de 0,11% ao mês
		cp.debita(1000); //adicionando 1000 reais ao saldo, para testar o juros
		cp.imprime();
		cp.addJuros();
		cp.imprime();
		cp.addJuros();
		cp.imprime();
		

	}

}
