package vetoresetc;

public class ex13 {

	public static void main(String[] args) {
		ListaDePalavras lp = new ListaDePalavras();
		
        lp.adiciona("Objetos Orientados a Objetos");
        
        System.out.println(lp);
        
        System.out.println("N�mero de vezes que a palavra 'Objetos' � armazenada: " + lp.contador("Objetos"));
        System.out.println("N�mero de vezes que a palavra 'Orientados' � armazenada: " + lp.contador("Orientados"));
        
        System.out.println("TreeSet n�o pode armazenar objetos duplicados");

	}

}
