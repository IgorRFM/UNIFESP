package homeTheater;

public class Main {

	public static void main(String[] args) {
		Sintonizadores sintonizador = new Sintonizadores();
		Amplificador amplificador = new Amplificador();
		
		sintonizador.conectar();
		sintonizador.varreduraDeCanais();
		sintonizador.verificarSinal();
		amplificador.conectar();
		amplificador.ajustarSom(15);
		amplificador.verificarSinal();
		
		CDPlayers cd = new CDPlayers();
		DVDPlayer dvd = new DVDPlayer();
		
		cd.ler();
		cd.reproduzir();
		dvd.ler();
		dvd.reproduzir();
		
		ProjetorMultimidia pm = new ProjetorMultimidia();
		TelasDeProjecao tp = new TelasDeProjecao();
		tp.reproduzir();
		pm.reproduzir();
		
		MaquinaDePipoca mp = new MaquinaDePipoca();
		MaquinaDeRefrigerante mr = new MaquinaDeRefrigerante();
		
		mp.verificarEnergia();
		mp.ligar();
		mr.verificarEnergia();
		mr.ligar();
		mr.ajustaTemperatura(7);
		
		Lampadas lampadas = new Lampadas();
		lampadas.interruptor();
		lampadas.intensidade(5);
		
		Janelas janela = new Janelas();
		janela.abrir();
		janela.abrir();
		
		Persianas p = new Persianas();
		p.abrir();
		
	}

}
