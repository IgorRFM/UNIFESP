package homeTheater;

public class Lampadas implements LuzAmbiente {
	private boolean ligado=false;
	public void interruptor() {
		if(ligado) {
			ligado=false;
			System.out.println("Desligando a luz...\n");
		}else {
			ligado=true;
			System.out.println("Ligando a luz...\n");
		}
	}
	
	public void intensidade(int nivel) {
		System.out.println("Ajustando nível de luz..\n");
	}

	@Override
	public void ajustar(int nivel) {
		intensidade(nivel);

	}

}
