package vetoresetc;

public class ex13 {

	public static void main(String[] args) {
		ListaDePalavras lp = new ListaDePalavras();
		
        lp.adiciona("Objetos Orientados a Objetos");
        
        System.out.println(lp);
        
        System.out.println("Número de vezes que a palavra 'Objetos' é armazenada: " + lp.contador("Objetos"));
        System.out.println("Número de vezes que a palavra 'Orientados' é armazenada: " + lp.contador("Orientados"));
        
        System.out.println("TreeSet não pode armazenar objetos duplicados");

	}

}
