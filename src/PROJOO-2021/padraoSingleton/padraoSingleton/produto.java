package padraoSingleton;

public class produto {
	public String[] prods = {"maça", "banana", "farinha", "macarrão"};
	public String[] id = {"223", "342", "007", "123"};
	public float[] preco = {2, 3, 10, 2};
	
	public float getPreco(String id) {
		int i=0;
		while(this.id[i] != id) {
			i++;
		}
		return this.preco[i];
	}
	

}
