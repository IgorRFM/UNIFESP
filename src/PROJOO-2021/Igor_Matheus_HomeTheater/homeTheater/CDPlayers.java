package homeTheater;

public class CDPlayers implements Reprodutor {

	@Override
	public void ler() {
		System.out.println("Lendo CD...\n");
		reproduzir();
	}

	@Override
	public void reproduzir() {
		System.out.println("Estabelecendo conex�es de �udio.\n");
		System.out.println("Reproduzindo CD...\n");
	}

}
