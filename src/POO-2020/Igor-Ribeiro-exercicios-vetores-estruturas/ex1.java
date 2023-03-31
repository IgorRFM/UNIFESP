package vetoresetc;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class ex1 {
	public static void main(String[] args) {
		Scanner teclado = new Scanner(System.in);
		ArrayList<Integer> entradas = new ArrayList<Integer>();
		int i = 0;
		do {
			entradas.add(teclado.nextInt());
			i++;
		}while(entradas.get(i-1) != 0 && i != 100);
		
		Collections.sort(entradas);
		System.out.println("Termos: " + entradas.toString());  
		
		teclado.close();
	}
	
}
