package arquivos;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class ex4 {

	public static void escritor(String path, Map<String,String> map) throws IOException {
		BufferedWriter buffWrite = new BufferedWriter(new FileWriter(path));

		Scanner in = new Scanner(System.in);
		//buffWrite.append(dados);

		Object[] a = map.keySet().toArray();
        Object[] b =  map.values().toArray();
        
        for (int j = 0; j < a.length; j++) {
        	buffWrite.append(a[j] + " " + b[j] + "\n");
	        }
        
		buffWrite.close();
	}
	
	public static void main(String[] args) throws IOException {
		Scanner teclado = new Scanner(System.in);
		
		System.out.println("Verifique se os arquivos a serem lidos estão no diretório " + new File(".").getAbsolutePath() + "\nDigite o nome do arquivo a se escrever: ");
		
		String entrada = teclado.nextLine();
		
		Map<String,String> map = new HashMap<String,String>();
		map.put("Igor", "2");
		map.put("umaPalavra", "1");
		map.put("outraPalavra", "10");
		map.put("Teste", "3");
       
		
		escritor(entrada, map);

	}

}
