package padraoBridge;

public class Lista extends Queue {

	@Override
	public int Size() {
		return implementor.size();
	}

	@Override
	public boolean isEmpty() {
		return implementor.isEmpty();
	}

	@Override
	public void Queue(String Item) {
		implementor.Queue(Item); 
		
	}

	@Override
	public void Dequeue() {
		implementor.Dequeue();
		
	}

	@Override
	public void print() {
		implementor.print();
		
	}

}
