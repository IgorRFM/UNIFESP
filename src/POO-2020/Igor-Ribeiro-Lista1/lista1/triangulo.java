package lista1;

public class triangulo extends figura{
	private double base, altura;
	public void setArea() {
		System.out.println("Digite o construtor com a base e a altura");
	}
	public void setArea(double base, double altura) {
		this.base=base;
		this.altura=altura;
		super.area = area(base/2, altura);
	}
	public String toString() {
		String resp="";
		resp+= "A base do triangulo é: " + base + " e sua altura é: " + altura + " ";
		resp+= super.toString();
		return resp;
		
	}
}
