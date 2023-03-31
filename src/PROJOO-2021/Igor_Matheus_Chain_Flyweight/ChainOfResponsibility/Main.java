package ChainOfResponsibility;

public class Main {

	public static void main(String[] args) {
		Chain chain = new Chain();
        
        //Calling chain of responsibility
        chain.process(new Texto("Isto é um teste."));
        chain.process(new Texto("Testando. as. Coisas."));
	}
}
