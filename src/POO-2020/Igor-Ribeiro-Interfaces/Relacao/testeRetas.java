package interfaces;

public class testeRetas extends retas {

	public static void main(String[] args) {
		// definindo uma reta r1
		retas r1 = new retas();
		
		double[] p1 = {-2,4};
		r1.setP1(p1);
		double[] p2 = {2,2};
		r1.setP2(p2);
		
		// definindo uma reta r2
		retas r2 = new retas();
		
		double[] p1_2 = {1,4};
		r2.setP1(p1_2);
		double[] p2_2 = {1,1};
		r2.setP2(p2_2);

	
		System.out.println("tamanho do R1: " + r1.tamanho());
		System.out.println("tamanho do R2: " + r2.tamanho());

		System.out.println("R1 é maior que R2? -> " + r1.maiorQue(r2));
		System.out.println("R1 é menor que R2? -> " + r1.menorQue(r2));
		System.out.println("R1 é igual a R2? -> " + r1.igualA(r2));
		
		
	}

}
