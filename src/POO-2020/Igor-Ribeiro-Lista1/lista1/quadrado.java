package lista1;

public class quadrado extends retangulo {
	private double lado;
	public void setArea() {
		System.out.println("Digite o construtor com a base e a altura");
	}
	public void setArea(double lado) {
		this.lado=lado;
		super.setArea(lado, lado);
	}
	
}
