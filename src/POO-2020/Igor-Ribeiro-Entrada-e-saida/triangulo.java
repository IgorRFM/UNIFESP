package entradaSaida;

public class triangulo {
	int a, b, c, perimetro;
	double area;
	String tipo;
	
	public String getTipo() {
		tipoTriangulo();
		return tipo;
	}
	public void setTipo(String tipo) {
		this.tipo = tipo;
	}
	public int getA() {
		return a;
	}
	public void setA(int a) {
		this.a = a;
	}
	public int getB() {
		return b;
	}
	public void setB(int b) {
		this.b = b;
	}
	public int getC() {
		return c;
	}
	public void setC(int c) {
		this.c = c;
	}
	public int getPerimetro() {
		calculaPerimetro();
		return perimetro;
	}
	public void setPerimetro(int perimetro) {
		this.perimetro = perimetro;
	}
	public double getArea() {
		calculaArea();
		return area;
	}
	public void setArea(double area) {
		this.area = area;
	}

	public void calculaArea() {
		calculaPerimetro();
		int semiP = this.perimetro/2;
		this.area = Math.sqrt(semiP*(semiP - this.a)*(semiP - this.b)*(semiP - this.c));
		
	}
	
	public void calculaPerimetro() {
		this.perimetro=this.a + this.b+this.c;
	}
	
	public boolean existe() {
		int ver = 0;
		int tempA, tempB;
		tempA = Math.abs(this.b- this.c);
		tempB = b+c;
		if(this.a > tempA && this.a < tempB) {
			ver++;
		}
		
		tempA = Math.abs(this.a- this.c);
		tempB = a+c;
		if(this.b > tempA && this.b < tempB) {
			ver++;
		}
		tempA = Math.abs(this.a- this.b);
		tempB = a+b;
		if(this.c > tempA && this.c < tempB) {
			ver++;
		}
		
		if(ver == 3) {
			return true;
		}else {
			return false;
		}
	}
	
	public void tipoTriangulo() {
		if(existe() == true) {
			if(this.a == this.b &&  this.a ==this.c){
				//equilátero
				//System.out.println("É um triangulo equilátero");
				this.tipo= "equilátero";
			}else if(this.a != this.b && this.a != this.c && this.b != this.c) {
				//escaleno
				//System.out.println("É um triangulo escaleno");
				this.tipo = "escaleno";
			}else {
				//isóceles
				//System.out.println("É um triangulo isóceles");
				this.tipo = "isóceles";
			}
		}else {
			//System.out.println("Não é um triangulo");
			this.tipo = "não é um triângulo";
		}
		
	}

}
