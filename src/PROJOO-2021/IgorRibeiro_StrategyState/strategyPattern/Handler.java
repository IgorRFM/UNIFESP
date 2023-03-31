package strategyPattern;

public class Handler{
	private Strategy novo;
	
	public Strategy diaSemana(int index) {
		if(index == 1) {
			novo = new Domingo();
		}else if(index == 2) {
			novo = new Segunda();
		}else if(index == 3) {
			novo = new Terca();
		}else if(index == 4) {
			novo = new Quarta();
		}else if(index == 5) {
			novo = new Quinta();
		}else if(index == 6) {
			novo = new Sexta();
		}else if(index == 0) {
			novo = new Sabado();
		}else {
			novo = null;
			System.out.println("Erro: Dia da semana inexistente.");
		}
		return novo;
		
	}

}
