package vetoresetc;

public class ex10 {

	public static void main(String[] args) {
		fila f = new fila();
        
        f.enfileira("Igor");
        f.enfileira("Yuri");
        f.enfileira("Jos�");
        f.enfileira("Christina");
        f.desenfileira();
        
        if(f.isVazio())
        	System.out.println("A fila est� vazia");
        else
        	System.out.println("A fila n�o est� vazia");
        
        System.out.println(f.toString());

	}

}
