package lista1;

public class mortal {
	private boolean vivo = true;
	
	public boolean isVivo() {
		return vivo;
	}
	
	public void mata() {
		vivo = false;
	}
}
