package vetoresetc;

public class ex4 {

	public static void main(String[] args) {
		int[] vetor = new int[10];
		
		//populando um vetor aleatoriamente
		System.out.println("Vetor aleatório: ");
		for(int i=0; i<10; i++) {
			vetor[i] = (int) (Math.random()*100);
			System.out.print(vetor[i] + " ");
		}
		
		System.out.println("\nMaior número: ");
		int maior = 0;
		for(int i = 0; i<vetor.length; i++)
			if(vetor[i] > maior)
				maior = vetor[i];
		
		System.out.println(maior);
	}

}
