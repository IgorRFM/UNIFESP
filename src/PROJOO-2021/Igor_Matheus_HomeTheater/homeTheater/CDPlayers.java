package homeTheater;

public class CDPlayers implements Reprodutor {

	@Override
	public void ler() {
		System.out.println("Lendo CD...\n");
		reproduzir();
	}

	@Override
	public void reproduzir() {
		System.out.println("Estabelecendo conexões de áudio.\n");
		System.out.println("Reproduzindo CD...\n");
	}

}
