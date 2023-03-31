package vetoresetc;

public class no {
	private int dado;
	private no prox;
	
	public no() {
		dado=0;
		prox = null;
	}
	
	public no(int dado, no prox) {
		this.dado = dado;
		this.prox = prox;
	}
	
	public int getDado() {
		return dado;
	}
	public void setDado(int dado) {
		this.dado = dado;
	}
	public no getProx() {
		return prox;
	}
	public void setProx(no prox) {
		this.prox = prox;
	}
	
}
