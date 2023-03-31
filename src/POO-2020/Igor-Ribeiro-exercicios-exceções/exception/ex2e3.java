package exception;

public class ex2e3 {

	public static void main(String[] args) {
		try{
		    boolean motorLigado = false; //criar um suposto controlador de status de um motor
		    motorDesligadoException e = new motorDesligadoException("Seu motor está desligado"); // instancia a classe de exception personalizada 
		    
		    if(!motorLigado) {
		    	throw e; //verifica se o erro está ocorrendo ou não, lançando um throw caso sim
		    	
		    	/*Exercício 3: caso o throw não esteja sendo lançado aqui, 
		    	 * O compilador dá o resultado de que é impossível entrar
		    	 * em um dos catchs e não deixa compilar o programa*/
		    	
		    }
		    
		} catch (motorDesligadoException e) { //recebe o throw
		    System.out.println("Ocorreu um erro: " + e.getMessage()); //apresenta o erro
		    }
		}

	}


