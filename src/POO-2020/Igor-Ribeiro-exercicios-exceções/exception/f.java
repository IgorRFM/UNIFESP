package exception;

public class f {

	public static void main(String[] args) {
		try {
			g teste = new g();
			teste.executa();
			
			if(!teste.motorligado) {
				throw new motorDesligadoException("O motor desligou");
			}
			
		}catch(motorDesligadoException e) {
			System.out.println("Houve um erro lógico: " + e.getMessage());
		}

	}

}
