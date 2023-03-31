package padraoSingleton;

public class bancodedados{
	private cliente[] clientes = new cliente[30];
	private int qtde=0;
	
	public void inserir(cliente cli) {
		clientes[qtde] = cli;
		qtde++;
		System.out.println("Cliente " + clientes[qtde-1].getNome() + " inserido com sucesso sob o ID: " + clientes[qtde-1].getID());
	}

}
