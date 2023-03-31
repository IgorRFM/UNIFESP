package arquivos;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;

public class ex3 {
	public static void leitor(String caminho) throws IOException{
		BufferedReader buffRead = new BufferedReader(new FileReader(caminho));
		String linha = "";
		Map<String,String> map = new HashMap<String,String>();

		while (true) {
			if (linha != null ) {
				if(linha != "") {
					String str= linha;
					String[] splitStr = str.trim().split("\\s+");
					if (map.get(splitStr[0]) == null) {
		                map.put(splitStr[0], splitStr[1]);
		            }
				}
			} else
				break;
			linha = buffRead.readLine();
		}
		
		Object[] a = map.keySet().toArray();
        Iterator i =  map.values().iterator();
        
        System.out.println("\nPalavras || Contadores ");
        for (int j = 0; j < a.length; j++) {
            System.out.print(a[j] + "  ");
            System.out.print(i.next() + "\n");
	        }
        
		buffRead.close();

	}
	
	public static void main(String[] args) throws IOException {
		Scanner teclado = new Scanner(System.in);
		
		System.out.println("Verifique se o arquivo a ser lido está no diretório " + new File(".").getAbsolutePath() + "\nDigite o nome do arquivo: ");
		
		String entrada = teclado.nextLine();
		leitor(entrada);
		

	}

}
