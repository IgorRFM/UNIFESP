package memento;

public class Memento {
	private String txt;
	
	public Memento(String txt) {
		this.txt = txt;
	}

	protected String getTxt() {
		return txt;
	}

	protected void setTxt(String txt) {
		this.txt = txt;
	}
	
}
