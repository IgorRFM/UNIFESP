package decorator;

public class Inv implements Texto{
	private String t;
	
	public Inv(String t) {
		this.t = t;
	}
	
	@Override
	public String getTexto() {
		return t;
	}

	@Override
	public void formatar() {
		StringBuilder sb = new StringBuilder(t);
		t = sb.reverse().toString();	
	}
	

}
