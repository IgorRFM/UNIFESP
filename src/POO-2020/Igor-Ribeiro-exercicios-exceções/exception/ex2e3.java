package exception;

public class ex2e3 {

	public static void main(String[] args) {
		try{
		    boolean motorLigado = false; //criar um suposto controlador de status de um motor
		    motorDesligadoException e = new motorDesligadoException("Seu motor est� desligado"); // instancia a classe de exception personalizada 
		    
		    if(!motorLigado) {
		    	throw e; //verifica se o erro est� ocorrendo ou n�o, lan�ando um throw caso sim
		    	
		    	/*Exerc�cio 3: caso o throw n�o esteja sendo lan�ado aqui, 
		    	 * O compilador d� o resultado de que � imposs�vel entrar
		    	 * em um dos catchs e n�o deixa compilar o programa*/
		    	
		    }
		    
		} catch (motorDesligadoException e) { //recebe o throw
		    System.out.println("Ocorreu um erro: " + e.getMessage()); //apresenta o erro
		    }
		}

	}


