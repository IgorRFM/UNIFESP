package vetoresetc;

import java.util.Arrays;
import java.util.Scanner;

public class ex1_2 {

	@SuppressWarnings("resource")
	public static void main(String[] args) {
		Scanner teclado = new Scanner(System.in);
		int[] entradas = new int[100];		
		int i = 0;
		do {
			entradas[i] = teclado.nextInt();
			i++;
		}while(entradas[i-1] != 0 && i != 100);
		
	    Arrays.sort(entradas);
	    
	    //para evitar o print de vários "0" no começo do vetor ordenado, eu pulei diretamente para o primeiro elemento não-nulo
	    for(int j = 100-i; j<100; j++)
	    	System.out.println(entradas[j]);
	    
	    teclado.close();
	}
	
}
