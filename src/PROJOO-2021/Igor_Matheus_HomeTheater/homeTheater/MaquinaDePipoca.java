package homeTheater;

import java.util.concurrent.TimeUnit;

public class MaquinaDePipoca implements Maquinas {
	
	private void notificar() {
		System.out.println("pipoca pronta!!\n");

	}


	@Override
	public void verificarEnergia() {
		System.out.println("VerificandoEnergia\n");


	}

	@Override
	public void ligar() {
		System.out.println("Ligando\n");
		try {
			TimeUnit.SECONDS.sleep(15);
			notificar();

		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
