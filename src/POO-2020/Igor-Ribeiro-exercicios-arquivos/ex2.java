package arquivos;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;

public class ex2 {

	public static String leitor(String caminho) throws IOException{
		BufferedReader buffRead = new BufferedReader(new FileReader(caminho));
		String linha = "";
		String Buffer="";
		while (true) {
			if (linha != null) {
				//System.out.println(linha);
				Buffer += linha+"\n";

			} else
				break;
			linha = buffRead.readLine();
		}
		buffRead.close();
		
		return Buffer;

	}
	
	public static void escritor(String path, String dados) throws IOException {
		BufferedWriter buffWrite = new BufferedWriter(new FileWriter(path));

		
		buffWrite.append(dados);
		buffWrite.close();
	}
	
	public static void main(String[] args) throws IOException {
		Scanner teclado = new Scanner(System.in);
		
		System.out.println("Verifique se os arquivos a serem lidos estão no diretório " + new File(".").getAbsolutePath() + "\nDigite o nome do arquivo que será copiado: ");
		
		String entrada = teclado.nextLine();
		String chars = leitor(entrada);
		
		System.out.println("Digite o nome do arquivo final: ");
		entrada = teclado.nextLine();

		escritor(entrada, chars);

	}

}
