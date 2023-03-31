package ex3_2;

import java.util.ArrayList;

public class Main{

	public static void main(String[] args) {
		Colecao jornal = new Colecao(new ArrayList<Publicacao>());
		jornal.addPublicacao(new Artigo("texto do artigo do jornal", "título do artigo do jornal", "autores do artigo do jornal"));
		
		Colecao caderno = new Colecao(new ArrayList<Publicacao>());
		caderno.addPublicacao(new Artigo("artigo do caderno", "texto do artigo do caderno", "autores do artigo do caderno"));
		jornal.addPublicacao(caderno);
		
		Colecao revista = new Colecao(new ArrayList<Publicacao>());
		revista.addPublicacao(new Artigo("texto da revista", "título do testo da revista", "autores do texto da revista"));
		caderno.addPublicacao(revista);
		
		System.out.println("Número de publicações: " + jornal.numero_de_publicacoes() + "\nPublicações: \n" + jornal.paraString());
		
		
		

	}

}
