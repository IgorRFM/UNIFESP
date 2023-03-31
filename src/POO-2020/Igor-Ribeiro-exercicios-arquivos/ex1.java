package arquivos;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;

public class ex1 {
	
	public static String leitor(String caminho) throws IOException{
		BufferedReader buffRead = new BufferedReader(new FileReader(caminho));
		String linha = "";
		String Buffer="";
		while (true) {
			if (linha != null) {
				//System.out.println(linha);
				Buffer += linha;

			} else
				break;
			linha = buffRead.readLine();
		}
		buffRead.close();
		
		return Buffer;

	}
	
	public static void contador(String chars) {
		Map<Character,Integer> map = new HashMap<Character,Integer>();

		 for (int i = 0; i < chars.length(); i++) {
	            if (map.get(chars.charAt(i)) == null) {
	                map.put(chars.charAt(i), 1);
	            }else {
	            	map.put(chars.charAt(i), map.get(chars.charAt(i)) + 1);
	            }
		 }
		 
		Object[] a = map.keySet().toArray();
        Iterator i =  map.values().iterator();
        
        System.out.println("\nQuantidade de letras: ");
        for (int j = 0; j < a.length; j++) {
            System.out.print(a[j] + " = ");
            System.out.print(i.next() + "\n");
	        }
	}
	
	public static void main(String[] args) throws IOException {
		Scanner teclado = new Scanner(System.in);
		
		System.out.println("Verifique se o arquivo a ser lido está no diretório " + new File(".").getAbsolutePath() + "\nDigite o nome do arquivo: ");
		
		String entrada = teclado.nextLine();
		String chars = leitor(entrada);
		
		contador(chars);

	}

}
