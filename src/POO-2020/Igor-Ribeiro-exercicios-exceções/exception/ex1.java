package exception;

public class ex1 {

	public static void main(String[] args) {
		try {
			IllegalArgumentException e = new IllegalArgumentException("Voc� passou algum argumento errado! "); //instanciando exception
			throw e; //for�ando um throw pro catch
			
		}catch(IllegalArgumentException e2) {
			System.out.println("Erro de argumento: " + e2.getMessage()); //imprimindo que teve um erro e, logo em seguida, a mensagem (String) passado como argumento do objeto instanciada
			
		}finally {
			System.out.println("Estou aqui. "); //�ltima etapa, isto ocorre independente do programa achar catchs ou n�o.
			
		}

	}

}
