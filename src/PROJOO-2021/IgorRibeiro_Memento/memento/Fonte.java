package memento;

public class Fonte {
	private String txt;
	
	private String ultimoSave;
	Zelador zelador;
	
	public Fonte(String txt, Zelador zelador) {
		this.txt = txt;
		this.zelador = zelador;
		createSave("INICIAL");
	}

	protected String getTxt() {
		return txt;
	}

	protected void setTxt(String txt) {
		this.txt = txt;
	}
	
	public void createSave(String nomeSave) {
		zelador.salvar(new Memento(this.txt), nomeSave);
		ultimoSave = nomeSave;
	}
	
	public void desfazer() {
		setEstadoFonte(ultimoSave);
	}
	
	private void setEstadoFonte(String nomeSave) {
		Memento mem = Zelador.getMemento(nomeSave);
		this.txt = mem.getTxt();
	}
	
}
