package homeTheater;

public class DVDPlayer implements Reprodutor {

	@Override
	public void ler() {
		System.out.println("Lendo DVD...\n");
		reproduzir();
	}

	@Override
	public void reproduzir() {
		System.out.println("Estabelecendo conex�es com v�deo.\n");
		System.out.println("Reproduzindo DVD...\n");
	}

}
