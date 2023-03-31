package exercicioTriangulo;

public class quadrado {
	int lado, area;
	
	public int getArea() {
		return area;
	}

	public int getLado() {
		return lado;
	}

	public void setLado(int lado) {
		this.lado = lado;
		this.area();
	}

	public void area() {
		this.area = this.lado * this.lado;
	}
	
	public quadrado(int lado) {
		this.setLado(lado);
	}


	public static void main(String[] args) {
		quadrado quad = new quadrado(5);
		System.out.println(quad.getArea());
		//testando o método de atualizar o valor do lado
		quad.setLado(7);
		System.out.println(quad.getArea());
		
		//instanciar 10 quadrados aleatórios com valores dos lados entre 0 e 100
		quadrado q1 = new quadrado((int) (Math.random()*100));
		System.out.println("Lado | area q1: "+ q1.getLado() + " | " + q1.getArea());
		quadrado q2 = new quadrado((int) (Math.random()*100));
		System.out.println("Lado | area q2: "+ q2.getLado() + " | " + q2.getArea());
		quadrado q3 = new quadrado((int) (Math.random()*100));
		System.out.println("Lado | area q3: "+ q3.getLado() + " | " + q3.getArea());
		quadrado q4 = new quadrado((int) (Math.random()*100));
		System.out.println("Lado | area q4: "+ q4.getLado() + " | " + q4.getArea());
		quadrado q5 = new quadrado((int) (Math.random()*100));
		System.out.println("Lado | area q5: "+ q5.getLado() + " | " + q5.getArea());
		quadrado q6 = new quadrado((int) (Math.random()*100));
		System.out.println("Lado | area q6: "+ q6.getLado() + " | " + q6.getArea());
		quadrado q7 = new quadrado((int) (Math.random()*100));
		System.out.println("Lado | area q7: "+ q7.getLado() + " | " + q7.getArea());
		quadrado q8 = new quadrado((int) (Math.random()*100));
		System.out.println("Lado | area q8: "+ q8.getLado() + " | " + q8.getArea());
		quadrado q9 = new quadrado((int) (Math.random()*100));
		System.out.println("Lado | area q9: "+ q9.getLado() + " | " + q9.getArea());
		quadrado q10 = new quadrado((int) (Math.random()*100));
		System.out.println("Lado | area q10: "+ q10.getLado() + " | " + q10.getArea());
		
		int soma = q1.getArea()+q2.getArea()+q3.getArea()+q4.getArea()+q5.getArea()+q6.getArea()+q7.getArea()+q8.getArea()+q9.getArea()+q10.getArea();
		System.out.println("\nSomatória de todas as áreas: " + soma);

	}

}
