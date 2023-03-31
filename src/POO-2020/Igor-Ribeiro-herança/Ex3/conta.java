package heranca;

public class conta {
	private double saldo;
	private int numero;
	public conta(int a) {
		saldo = 0.0;
		numero = a;
	}
	
	public void debita (double quantia) {
		if(quantia > 0) {
			saldo += quantia;
		}else {
			System.err.println("Depósito negativo");
		}
	}
	
	public void credita (double quantia) {
		if(quantia > 0) {
			saldo -= quantia;
		}else {
			System.err.println("saque negativo");
		}		
	}
	
	public double getSaldo() { return saldo;}
	public double getNumero() { return numero;}
	
	public void imprime() {
		System.out.println("Conta " + numero + ": Saldo= " + saldo);
	}


}
