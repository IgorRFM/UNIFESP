package lista1;

public class figura {
	public double area;
	
	public double getArea() {
		return area;
	}
	
	public double area(double base, double altura) {
		double area = base * altura;
		return area;
	}
	
	public String toString() {
		String resp="";
		resp += "Área da figura = " + area + " ";
		return resp;
	}
	
}
