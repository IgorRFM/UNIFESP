package decorator;

public class Caps implements Texto{
	private String t;
	
	public Caps(String t) {
		this.t = t;
	}
	
	@Override
	public String getTexto() {
		return t;
	}

	@Override
	public void formatar() {
		t = t.toUpperCase();
		
	}
}
