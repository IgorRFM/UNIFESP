package exercicioTriangulo;

public class retangulo {
	int base, altura, area, perimetro;

	public int getBase() {
		return base;
	}



	public void setBase(int base) {
		this.base = base;
	}



	public int getAltura() {
		return altura;
	}



	public void setAltura(int altura) {
		this.altura = altura;
	}



	public int getArea() {
		return area;
	}



	public void setArea(int area) {
		this.area = area;
	}



	public int getPerimetro() {
		return perimetro;
	}



	public void setPerimetro(int perimetro) {
		this.perimetro = perimetro;
	}
	
	public void area() {
		this.area = this.altura * this.base;
	}
	
	public void perimetro() {
		this.perimetro = 2*this.altura + 2*this.base;
	}
	
	public float baseAltura() {
		float prop = (float) (this.base*1.00 / this.altura);
		return prop;
	}
	
	public boolean isQuadrado() {
		return this.base == this.altura;
	}
	
	public void mostrar() {
		System.out.println("O retângulo tem \naltura: " + this.altura + "\nbase: " + this.base + "\narea: " + this.area + "\nperimetro: " +this.perimetro+ "\nrelação base/altura: " + baseAltura());
		if(isQuadrado() == true) {
			System.out.println("e é um retângulo quadrado.");
		}else {
			System.out.println("e não um retângulo quadrado.");
		}
	}



	public static void main(String[] args) {
		retangulo r1 = new retangulo();
		r1.setAltura(20);
		r1.setBase(5);
		
		r1.area();
		r1.perimetro();
		r1.mostrar();
		
		System.out.println("\n\n.");

		
		r1.setAltura(30);
		r1.setBase(30);
		
		r1.area();
		r1.perimetro();
		r1.mostrar();
		
		
		
	}

}
