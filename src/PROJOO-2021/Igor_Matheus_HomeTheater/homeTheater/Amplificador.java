package homeTheater;

public class Amplificador implements Sinal {
	public void ajustarSom(int nivel) {
		System.out.println("Ajustando volume em " + nivel + "dB\n");
	}

	@Override
	public void conectar() {
		System.out.println("Se conectando ao reprodutor de Som...\n");

	}

	@Override
	public void verificarSinal() {
		System.out.println("Verificando estabilidade do sinal...\n");

	}

}
