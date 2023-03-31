package lista1;

public class circulo extends figura{
	private double raio;
	public void setArea() {
		System.out.println("Digite o construtor com o raio do círculo. c.setArea(10); por ex");
	}
	public void setArea(double raio) {
		this.raio=raio;
		double area = 3.14 * raio * raio;
		super.area = area;
	}
	public String toString() {
		String resp="";
		resp+= "O raio do círulo é: " + raio + " ";
		resp+= super.toString();
		return resp;
		
	}
	

}
