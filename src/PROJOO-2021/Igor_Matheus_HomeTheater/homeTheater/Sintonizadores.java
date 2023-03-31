package homeTheater;

public class Sintonizadores implements Sinal {
	
	public void varreduraDeCanais() {
		System.out.println("Verificando uma varredura de canais e atualizando a lista...\n");
	}

	@Override
	public void conectar() {
		System.out.println("Se conectando ao dispositivo de televis�o...\n");

	}

	@Override
	public void verificarSinal() {
		System.out.println("Verificando conex�o com o sat�lite...\n");

	}

}
