package padraoBridge;

public class VectorQ implements FIFOQueue {
	private String[] lista= new String[100];
	private int tam = 0;

	@Override
	public int size() {
		return tam;
	}

	@Override
	public boolean isEmpty() {
		return tam==0;
	}

	@Override
	public void Queue(String Item) {
		lista[tam] = Item;
		tam++;
	}

	@Override
	public void Dequeue() {
		lista[tam-1]="";
		tam--;
		
	}
	
	@Override
	public void print() {
		for(int i=0; i<tam; i++) {
			System.out.print(lista[i]+" ");
		}
		System.out.print("\n");
		
	}

}
