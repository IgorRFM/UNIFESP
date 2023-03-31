package exception;

public class ex4 {

	public static void main(String[] args) {
		
		/*
		 * Referencia inicialmente feita:
		 * 
		 * int[] teste = null;
		 * int a = teste[0]; 
		*/
		
		try {
			int[] teste = null;
			int a = teste[0];
		}catch(NullPointerException e) {
			System.out.println("Erro de referência: "+ e.getMessage());
		}

	}

}
