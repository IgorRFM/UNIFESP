package lista1;

public class retangulo extends figura{
	private double base, altura;
	public void setArea() {
		System.out.println("Digite o construtor com a base e a altura");
	}
	public void setArea(double base, double altura) {
		this.base=base;
		this.altura=altura;
		super.area = area(base, altura);
	}
	public String toString() {
		String resp="";
		resp+= "A base do retangulo �: " + base + " e sua altura �: " + altura + " ";
		resp+= super.toString();
		return resp;
		
	}
}
