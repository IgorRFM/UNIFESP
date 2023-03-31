package ex3_1;

import java.util.ArrayList;

public class testes {
	/*
	 * Código implementado por Igor Ribeiro Ferreira de Matos e Matheus de Souza Meire da Silva
	 */

	public static void main(String[] args) {
		//add(nome, assento);
		
		
		instituicao senado = new instituicao(new ArrayList<Congresso>());
		senado.Add(new individuo("Marco alves", "01"));
		senado.Add(new individuo("Igor ribeiro", "02"));
		senado.Add(new individuo("Lucas José", "06"));
		
		instituicao camara = new instituicao(new ArrayList<Congresso>());
		camara.Add(new individuo("Matheus de Souza", "20"));
		camara.Add(new individuo("Marcio Feliciano", "22"));
		camara.Add(new individuo("José Batista", "21"));
		
		instituicao deputados = new instituicao(new ArrayList<Congresso>());
		deputados.Add(new individuo("Vigor Almeida", "25"));
		deputados.Add(new individuo("Fernando Almeida", "26"));
		deputados.Add(new individuo("João clóvis", "27"));
		camara.Add(deputados);
		
		System.out.println("Senadores" + "(total participantes: " + senado.totalParticipantes() + ", total de assentos: " + senado.totalAssentos()+"):\n");
		senado.Exibir();
		
		System.out.println("Deputados" + "(total participantes: " + camara.totalParticipantes() + ", total de assentos: " + camara.totalAssentos()+"):\n");
		camara.Exibir();

	}

}
