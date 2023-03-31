package entradaSaida;

import java.util.Scanner;

public class entradaSaida {

	public static void main(String[] args) {
		String resp;
		System.out.println("Voc� deseja criar um quadrado ou triangulo?");
		Scanner teclado = new Scanner(System.in);
		resp = teclado.next();
		if(resp.equalsIgnoreCase("triangulo")) {
			System.out.println("Voc� escolheu triangulo!");
			triangulo t = new triangulo();
			int a, b, c;
			System.out.println("Digite os tr�s lados do triangulo, separados por um espa�o: ");
			a = teclado.nextInt();
			b = teclado.nextInt();
			c = teclado.nextInt();
			t.setA(a);
			t.setB(b);
			t.setC(c);
			if(t.existe() == true) {
				System.out.println("�rea: " + t.getArea());
				System.out.println("Per�metro: " + t.getPerimetro());
				System.out.println("Tipo: " + t.getTipo());
			}else {
				System.out.println("Tipo: " + t.getTipo());
			}
			
			
			
		}else if(resp.equalsIgnoreCase("quadrado")) {
			System.out.println("Voc� escolheu quadrado!");
			System.out.println("Digite o tamanho do lado do quadrado: ");
			int a = teclado.nextInt();
			quadrado q = new quadrado();
			q.setLado(a);
			System.out.println("�rea: " + q.getArea());
			System.out.println("Per�metro: " + q.getPerimetro());
			
			
		}else {
			System.out.println("Voc� n�o escolheu uma figura dispon�vel.");

		}
		teclado.close();
	}

}
