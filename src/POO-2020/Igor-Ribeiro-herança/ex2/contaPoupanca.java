package heranca;

public class contaPoupanca extends conta {
	public contaPoupanca(int numero) {
		super(numero);
	}

	double juros;

	public void setJuros(double juros) {
		this.juros = juros;
	}
	
	public void atualiza() {
		double jur = super.getSaldo() * this.juros / 100;
		super.debita(jur);
		super.imprime();
	}
	
	
	
	
}
