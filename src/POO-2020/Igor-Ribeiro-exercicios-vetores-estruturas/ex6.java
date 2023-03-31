package vetoresetc;

public class ex6 {

	public static void main(String[] args) {
		listaLigada l1 = new listaLigada();
		

        
        l1.inserir(1);
        l1.inserir(2);
        l1.inserir(4);
        l1.inserir(3);
        l1.imprimir();
        
        l1.remove(3);
        l1.imprimir();
        
        listaLigada l2 = l1.inverterLista();
        
        System.out.print("Lista invertida: ");
        l2.imprimir();
        
        System.out.print("Soma dos elementos: " + l1.soma() + "\n");

	}

}
