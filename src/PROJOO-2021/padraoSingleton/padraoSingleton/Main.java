package padraoSingleton;

public class Main {

	public static void main(String[] args) {
		singleton s = singleton.getInstance();
		
		s.registrar("Zé", 123);
		
		s.comprar("223", "123");
		s.comprar("342", "123");
		
		s.fecharCompra();

	}

}
