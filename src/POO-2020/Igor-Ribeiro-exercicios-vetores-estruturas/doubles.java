package vetoresetc;

public class doubles {
	private int tam;
	private double[] vet;
	
	public doubles(int tam) {
		this.vet = new double[tam];
	}
	
	public void popula() {
		for(int i=0; i<this.vet.length; i++) {
			this.vet[i] = Math.random();
		}
	}
	
	public void imprimir() {
		for(int i=0; i<this.vet.length; i++) {
			System.out.print(this.vet[i] + " | ");
		}
	}
}
