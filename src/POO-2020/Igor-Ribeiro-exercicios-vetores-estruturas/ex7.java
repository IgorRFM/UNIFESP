package vetoresetc;

public class ex7 {
	static void imprimeAlgo(int nivel) {
		if (nivel == 0) {
			System.out.print("*");
		} else {
			System.out.print("[");
			imprimeAlgo(nivel - 1);
			System.out.print(",");
			imprimeAlgo(nivel - 1);
			System.out.println("]");
		}
	}
	
	public static void main(String[] args) {
		//imprimeAlgo(0); // saída: *
		//imprimeAlgo(1); // saída: [*,*]
		//imprimeAlgo(2); // Saída: [[*,*],[*,*]]
		//imprimeAlgo(3); // Saída: [[[*,*],[*,*]],[[*,*],[*,*]]]

	}
}
