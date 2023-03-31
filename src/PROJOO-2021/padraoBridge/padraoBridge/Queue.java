package padraoBridge;

public abstract class Queue {
	protected FIFOQueue implementor;
	public abstract int Size();
	public abstract boolean isEmpty();
	public abstract void Queue(String Item);
	public abstract void Dequeue();
	public abstract void print();
}
