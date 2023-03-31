package vetoresetc;

public class ex10 {

	public static void main(String[] args) {
		fila f = new fila();
        
        f.enfileira("Igor");
        f.enfileira("Yuri");
        f.enfileira("José");
        f.enfileira("Christina");
        f.desenfileira();
        
        if(f.isVazio())
        	System.out.println("A fila está vazia");
        else
        	System.out.println("A fila não está vazia");
        
        System.out.println(f.toString());

	}

}
