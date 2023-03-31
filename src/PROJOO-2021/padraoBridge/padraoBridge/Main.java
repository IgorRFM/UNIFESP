package padraoBridge;

public class Main {

	public static void main(String[] args) {
		Lista listaArray = new Lista();
		FIFOQueue array = new ArrayListQ();
		listaArray.implementor=array;
		
		Lista listaVetor = new Lista();
		FIFOQueue vetor = new VectorQ();
		listaVetor.implementor=vetor;
		
		listaArray.Queue("item 1");
		listaArray.Queue("item 2");
		listaArray.Queue("item 3");
		listaArray.Queue("item 4");
		listaArray.print();
		listaArray.Dequeue();
		listaArray.print();
		
		listaVetor.Queue("item a");
		listaVetor.Queue("item b");
		listaVetor.Queue("item c");
		listaVetor.Queue("item d");
		listaVetor.print();
		listaVetor.Dequeue();
		listaVetor.print();
		
	}

}
