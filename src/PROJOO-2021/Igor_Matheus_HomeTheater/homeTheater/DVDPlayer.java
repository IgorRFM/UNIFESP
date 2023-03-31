package homeTheater;

public class DVDPlayer implements Reprodutor {

	@Override
	public void ler() {
		System.out.println("Lendo DVD...\n");
		reproduzir();
	}

	@Override
	public void reproduzir() {
		System.out.println("Estabelecendo conexões com vídeo.\n");
		System.out.println("Reproduzindo DVD...\n");
	}

}
