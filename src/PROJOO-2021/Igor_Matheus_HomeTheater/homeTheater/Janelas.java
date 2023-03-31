package homeTheater;

public class Janelas implements LuzAmbiente {
	private boolean aberta=false;
	
	public void abrir() {
		if(aberta) {
			aberta=false;
			System.out.println("Fechando janela...\n");
		}else {
			aberta=true;
			System.out.println("Abrindo janela...\n");
		}
	}

	@Override
	public void ajustar(int nivel) {
		//

	}

}
