package ex3_2;

import java.util.List;

public class Colecao implements Publicacao {
	private List<Publicacao> pubs;
	private int count=0;
	
	
	public Colecao(List<Publicacao> pubs) {
		this.pubs = pubs;
	}
	
	public void addPublicacao(Publicacao publicacao) {
		this.pubs.add(publicacao);
	}

	public void addPublicacao(Publicacao publicacao, String nome, String pub) {
		this.pubs.add(publicacao);
	}
	
	@Override
	public int numero_de_publicacoes() {		
		for(Publicacao pub : pubs) {
			count += pub.numero_de_publicacoes();
		}
		
		return count;
	}

	@Override
	public String paraString() {
		String texto="";
		

		for(Publicacao pub : pubs) {
			texto += pub.paraString() + "\n\n";
		}
		return texto;
	}


}
