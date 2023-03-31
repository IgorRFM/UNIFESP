package decorator;

public class Tag implements Texto{
	private String t="";
	
	public Tag(String t) {
		this.t=t;
	}
	
	@Override
	public String getTexto() {
		return t;
	}

	@Override
	public void formatar() {
		t="<b>" + t + "</b>";
		
	}

}
