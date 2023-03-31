package homeTheater;

public class ProjetorMultimidia implements Video {

	private void calculaIluminacao() {
		System.out.println("Definindo brilho\n");
	}
	
	@Override
	public void reproduzir() {
		// TODO Auto-generated method stub
		System.out.println("Lendo arquivos para reproduzir...\n");
		calculaIluminacao();

	}

}
