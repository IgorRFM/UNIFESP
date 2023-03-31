package homeTheater;

public class Sintonizadores implements Sinal {
	
	public void varreduraDeCanais() {
		System.out.println("Verificando uma varredura de canais e atualizando a lista...\n");
	}

	@Override
	public void conectar() {
		System.out.println("Se conectando ao dispositivo de televisão...\n");

	}

	@Override
	public void verificarSinal() {
		System.out.println("Verificando conexão com o satélite...\n");

	}

}
