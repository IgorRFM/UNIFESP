package lista;

public class mainClass {

	public static void main(String[] args) {
		System.out.println("\\PILHA: LIFO");
		pilha LP = new pilha();
		LP.add(5);
		LP.add(6);
		LP.add(7);
		System.out.println("Elementos na pilha (em ordem): ");
		LP.print();
		((pilha) LP).remover();
		System.out.println("Elementos na pilha (em ordem): ");
		LP.print();	

		System.out.println("\n\n\\LISTA: FIFO");
		fila LF =  new fila();
		System.out.println("Elementos na fila (em ordem): ");
		LF.add(1);
		LF.add(2);
		LF.add(3);
		LF.print();
		System.out.println("Elementos na fila (em ordem): ");
		LF.remover();
		LF.print();


	}

}
