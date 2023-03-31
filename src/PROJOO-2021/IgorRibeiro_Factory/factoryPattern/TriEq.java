package factoryPattern;

public  class TriEq implements Figura {

	@Override
	public double area(double x) {
		
		return ((x*x)*Math.sqrt(3))/4;
	}


}
