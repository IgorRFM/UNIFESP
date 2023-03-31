package lista;

public class mainClass {

	public static void main(String[] args) {
		lista l = new lista();
		l.criar();
		l.add(1);
		l.add(2);
		l.add(3);
		l.print();
		no temp;
		temp = l.procurar(2);
		System.out.println("Elemento achado: " + temp.getNum());
		int tamanho = lista.tamanho();
		System.out.println("tamanho da lista: " + tamanho);

	}

}
