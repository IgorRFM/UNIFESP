package vetoresetc;

import java.util.LinkedList;

public class fila {
    private LinkedList item;
    private int frente, tras;
    
    public fila() {
        item = new LinkedList();
        frente = tras = 0;
    }
    
    public boolean isVazio() {
        return frente == tras;
    }
    
    public void enfileira(Object x) {
        item.add(tras, x);
        tras++;
    }
    
    public boolean desenfileira() {
        if(isVazio()) return false;
        item.remove(frente);
        frente++;
        return true;
    }
    
    @Override
    public String toString() {
    	if(isVazio()) {
    		return "Fila vazia!";
    	}else {
    		return item.toString();
    	}
        
    }
}

