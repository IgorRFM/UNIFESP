package exercicioTriangulo;

public class triangulo {
	int altura, base, area;
	
	public int getAltura() {
		return altura;
	}


	public void setAltura(int altura) {
		this.altura = altura;
	}


	public int getBase() {
		return base;
	}


	public void setBase(int base) {
		this.base = base;
	}


	public int getArea() {
		return area;
	}


	public void setArea(int area) {
		this.area = area;
	}
	
	public void area() {
		this.area = (this.altura * this.base)/2;
	}
	
	public void mostra() {
		System.out.println("A área do triângulo é: " + this.area);
	}
	
	public triangulo() {
		this.altura = 5;
		this.base = 2;
	}
	
	public triangulo(int altura, int base) {
		this.altura = altura;
		this.base = base;
	}


	public static void main(String args[]) {
		//area: 5 * 2   /2 = 5
		triangulo t1 = new triangulo();
		t1.area();
		t1.mostra();
		
		//area: 25 * 8 /2 = 100
		triangulo t2 = new triangulo(25, 8);
		t2.area();
		t2.mostra();
		
		//area: 70 * 8 /2 = 240
		t2.setAltura(70);
		t2.area();
		t2.mostra();
	}
}
