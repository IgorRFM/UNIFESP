package vetoresetc;

import java.util.LinkedList;

public class pilha {
    @SuppressWarnings("rawtypes")
	private LinkedList item;
    private int topo;
    
    @SuppressWarnings("rawtypes")
	public pilha() {
        item = new LinkedList();
        topo = 0;
    }
    
    @SuppressWarnings("unchecked")
	public void push(Object x) {
        item.add(topo, x);
        topo++;
    }
    
    public void pop() {
        topo--;
        item.remove(topo);
    }

    @Override
    public String toString() {
        return item.toString();
    }
    
    public Object top() {
        return item.peekLast();
    }
    

}
