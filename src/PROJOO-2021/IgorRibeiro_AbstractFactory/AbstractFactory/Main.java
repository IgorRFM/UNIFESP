package AbstractFactory;

public class Main {

	public static void main(String[] args) {
		Figuras fa = new Figuras(null);
		
		Fig f1,f2,f3,f4;
		
		System.out.println("Contruindo o Ponto:");
		f1 = fa.getShape("ponto", 5, 5);
		
		System.out.println("\n\nContruindo o Circulo:");
		Ponto centro = new Ponto(1.0, 0.5);
		f2 = fa.getShape("Circulo", centro, 15.0);
		
		System.out.println("\n\nContruindo o Retangulo:");
		Ponto r1 = new Ponto(0.0,0.0);
		Ponto r2 = new Ponto(5.0, 10.0);
		f3= fa.getShape("retangulo", r1,r2);
		
		System.out.println("\n\nContruindo o Triangulo:");
		Ponto t1 = new Ponto(0.0,0.0);
		Ponto t2 = new Ponto(5.0, 5.0);
		Ponto t3 = new Ponto(9.0, 9.0);
		f4 = fa.getShape("triangulo", t1, t2, t3);
		
		
		
		
		

	}

}
