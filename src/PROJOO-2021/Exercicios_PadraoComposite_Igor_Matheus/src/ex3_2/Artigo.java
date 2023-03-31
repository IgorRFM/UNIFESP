package ex3_2;

public class Artigo implements Publicacao {
	private String nome;
	private String autores;
	private String pub;
	
	public Artigo(String nome, String autores, String artigo) {
		this.nome=nome;
		this.autores=autores;
		this.pub = artigo;
	}

	@Override
	public int numero_de_publicacoes() {
		// TODO Auto-generated method stub
		return 1;
	}

	@Override
	public String paraString() {
		String texto="";
		texto = nome + "\n" + pub + " (" + autores + ")";
		return texto;
	}

}
