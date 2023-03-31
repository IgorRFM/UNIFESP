package padraoSingleton;

public class carrinho{
	public String[] compra = new String[15];
	public int qtde=0;

	public void abrir() {
		// TODO Auto-generated method stub
		
	}

	public void adicionar(String idProd, String idCli) {
		compra[qtde] = idProd;
		qtde++;
	}

}
