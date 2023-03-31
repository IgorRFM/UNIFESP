package vetoresetc;

import java.util.Scanner;

public class ex2 {

	public static void main(String[] args) {
		Scanner teclado = new Scanner(System.in);
		System.out.print("tamanho do vetor: ");
		int tam = teclado.nextInt();

		double[] entradas = new double[tam];
		double med = 0;
		
		//leitura dos doubles
		for(int i=0; i<tam; i++) {
			entradas[i] = teclado.nextDouble();
		}
		
		//calculo da média do vetor
		for(int i=0; i<tam; i++) {
			med += entradas[i];
		}
		
		med = med/tam;
		
		System.out.println("A média é: " + med);
		
		teclado.close();
		
		
	}

}
