package ex16_1;

public abstract class Comparar {
	abstract void iniciar(String[] palavras);
	abstract void finalizar(String[] palavras);
	abstract void ordenar(String[] palavras);
	
	public final void comp(String[] palavras) {
		iniciar(palavras);
		ordenar(palavras);
		finalizar(palavras);
	}
	
}
