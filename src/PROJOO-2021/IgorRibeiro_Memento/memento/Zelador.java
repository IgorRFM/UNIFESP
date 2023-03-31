package memento;

import java.util.HashMap;
import java.util.Map;

public class Zelador {
	private final static Map<String, Memento>savepointStorage = new HashMap<String,Memento>();
	
	public void salvar(Memento memento, String nomeSave) {
		System.out.println("salvando estado..."+ nomeSave);
		savepointStorage.put(nomeSave, memento);
	}
	
	public static Memento getMemento(String nomeSave) {
		return savepointStorage.get(nomeSave);
	}
}
