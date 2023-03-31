package heranca;

import java.util.Scanner;

public class Banco {
	public static void main(String[] args) { 
		int contas=0;
		//System.out.println("Você deseja criar que tipo de conta?\n[0]Conta corrente\n[1]Conta poupança\n[2]Conta");
		//String resp = teclado.next();
		contaCorrente cc = (contaCorrente) abrirConta(contas, "1");
		contas++;
		contaPoupanca cp = (contaPoupanca) abrirConta(contas, "2");
		contas++;
		
		cc.debita(300);
			cc.imprime();
		cp.debita(1000);
			cp.imprime();
		
		cc.dividendos();
			cc.imprime();
		cp.dividendos();
			cp.imprime();
		
		cc.fecharConta();
			cc.imprime();
		cp.fecharConta();
			cp.imprime();

		
	}
	public static conta abrirConta(int num, String tipo) {
		Scanner teclado = new Scanner(System.in);
		String resp=tipo;
		
		if(resp.equals("1")){
			conta nova = new contaCorrente(num);
			return nova;
		}else if(resp.equals("2")) {
			conta nova = new contaPoupanca(num);
			return nova;

		}else {
			conta nova = new conta(num);	
			return nova;
		}
	}
	

}
