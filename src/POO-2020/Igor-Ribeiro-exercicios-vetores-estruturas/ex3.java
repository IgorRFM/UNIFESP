package vetoresetc;

public class ex3 {

	public static void main(String[] args) {
		Funcionario[] f = new Funcionario[5];
		
		f[0] = new Funcionario("Igor", "Ribeiro", 12.5, 3);
		f[1] = new Funcionario("Yuri", "Araujo", 10.5, 8);
		f[2] = new Funcionario("Lucas", "Souza", 5.2, 1);
		f[3] = new Funcionario("José", "Arnaldo", 7, 5);
		f[4] = new Funcionario("Chris", "Tina", 25, 12);
		
		int x = 3;
		f[0].imprimir(f, x);
		
		System.out.print("\n\n");
		 x = 8;
		f[0].imprimir(f, x);
		

	}

}
