package ex16_1;

import java.util.Arrays;

public class CompPalavras extends Comparar{
	

	@Override
	void iniciar(String[] palavras) {
		System.out.println("Palavras a serem ordenadas:");
		for(int i=0; i<palavras.length;i++) {
			System.out.println(palavras[i]);
		}
				
	}

	@Override
	void finalizar(String[] palavras){
		System.out.println("\nPalavras ordenadas:");
		for(int i=0; i<palavras.length;i++) {
			System.out.println(palavras[i]);
		}
		
		
		
	}

	@Override
	void ordenar(String[] palavras) {
		Arrays.sort(palavras, new comp());
	}
	

}
