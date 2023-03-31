package homeTheater;

public class MaquinaDeRefrigerante implements Maquinas {
	final double TEMP_PADRAO = 5;
	public void ajustaTemperatura(double temp) {
		System.out.println("Ajustando temperatura em " + temp + " ºC\n");
	}

	@Override
	public void verificarEnergia() {
		System.out.println("VerificandoEnergia\n");


	}

	@Override
	public void ligar() {
		System.out.println("Ligando\n");
		ajustaTemperatura(TEMP_PADRAO);
	}

}
