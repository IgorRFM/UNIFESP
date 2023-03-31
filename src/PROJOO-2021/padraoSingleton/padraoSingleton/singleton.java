package padraoSingleton;

public class singleton {
	 private static singleton INSTANCE;
	 public carrinho carro;
	 public cliente cli;
	 public produto prod;
	 public bancodedados bd;

	 private singleton() {  
		 carro = new carrinho();
		 cli = new cliente();
		 prod = new produto();
		 bd = new bancodedados();
	 }

	 public static singleton getInstance() {
	        if(INSTANCE == null) {
	            INSTANCE = new singleton();
	        }
	        
	        return INSTANCE;
	    }
	 
	 public void registrar(String nome, int id) {
		cli.novoCliente(nome, id);
		bd.inserir(cli);
		carro.abrir();
	 }
	 public void comprar(String idProd, String idCli ) {
		 carro.adicionar(idProd, idCli);
		 
	 }
	 public void fecharCompra() {
		 float precoTotal=0;
		 for(int i=0; i<carro.qtde; i++) {
			 precoTotal += prod.getPreco(carro.compra[i]);
		 }
		 System.out.println("O total da compra foi: " + precoTotal);
	 }
}
