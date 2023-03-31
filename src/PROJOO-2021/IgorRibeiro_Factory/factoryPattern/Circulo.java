package factoryPattern;

public class Circulo implements Figura {

	@Override
	public double area(double x) {
		
		return Math.PI*x*x;
	}


}
