package AbstractFactory;

public class Circulo implements Fig {
	public double raio;
	public Ponto centro;
	
	public Circulo(Ponto centro, double e) {
		this.centro=centro;
		this.raio=e;
		
		System.out.println("\nCirculo construído com raio = "+e+" centro = ("+centro.getX()+","+centro.getY()+")");
	}

	@Override
	public void draw() {
		System.out.println("\nCirculo");
		
	}

}
