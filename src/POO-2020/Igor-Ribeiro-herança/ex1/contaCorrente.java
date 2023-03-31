package heranca;

public class contaCorrente extends conta{
	public contaCorrente(int numero) {
		super(numero);
		// TODO Auto-generated constructor stub
	}

	double limite;

	public void credita(double quantia){
		if (super.getSaldo() - quantia < limite*-1) {
			System.out.println("Limite estourado, saque recusado");
		}else {
			super.credita(quantia);
		}
	}
	
	public double getLimite() {
		return limite;
	}

	public void setLimite(double limite) {
		this.limite = limite;
	}
	
	
}
