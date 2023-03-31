package padraoBridge;

import java.util.ArrayList;

public class ArrayListQ implements FIFOQueue {
	private ArrayList<String> lista = new ArrayList<String>();

	@Override
	public int size() {
		
		return lista.size();
	}

	@Override
	public boolean isEmpty() {
		return lista.isEmpty();
	}

	@Override
	public void Dequeue() {
		lista.remove(lista.size()-1);
		
	}

	@Override
	public void Queue(String Item) {
		lista.add(Item);
		
	}

	@Override
	public void print() {
		System.out.println(lista);
		
	}

}
