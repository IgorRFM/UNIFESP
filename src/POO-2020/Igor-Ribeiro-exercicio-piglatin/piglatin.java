package string;

import java.util.Scanner;
import java.util.StringTokenizer;

public class piglatin {

	public static void main(String[] args) {
		Scanner teclado = new Scanner(System.in);
		String frase = teclado.nextLine(), p="", resp="";
		
		StringTokenizer t = new StringTokenizer(frase);
		
		for(; t.hasMoreTokens();) {
			p = t.nextToken();
			p = p.substring(1).concat(p.substring(0, 1)).concat("ay");
			resp += p + " ";
		}
		
		System.out.println("Tradução: " + resp);

	}

}
