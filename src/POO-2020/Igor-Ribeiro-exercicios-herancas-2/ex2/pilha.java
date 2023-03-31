package lista;

public class pilha extends lista {
	@SuppressWarnings("static-access")
	public void remover() {
		super.primeiro = super.primeiro.getP();
	}
}
