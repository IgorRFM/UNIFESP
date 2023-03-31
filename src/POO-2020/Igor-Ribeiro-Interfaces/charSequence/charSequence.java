package interfaces;

public class charSequence implements charSeq{
	private char[] entrada;
	private char[] invertida;
	
	

	public synchronized void setEntrada(char[] entrada) {
		invertida = new char[entrada.length];
		int a = entrada.length;
		for(int i = 0; i<entrada.length; i++){
			a--;
			invertida[a] = entrada[i];
		}
		
		this.entrada = invertida;
	}

	@Override
	public char charAt(int index) {
		
		return invertida[index];
	}

	@Override
	public int lenght() {
		int tamanho = entrada.length;
		return tamanho;
	}

	@Override
	public CharSequence subSequence(int start, int end) {
		char[] sub = new char[end-start];
		int a = 0;
		for(int i = start; i<end; i++) {
			sub[a] = invertida[i];
			
			a++;
			
			
		}
		
		CharSequence s = new String(sub);
		
		return s;
	}
	
	public String toString() {
		
		return new String(invertida);
	}

}
