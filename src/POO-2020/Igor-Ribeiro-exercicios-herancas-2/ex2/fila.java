package lista;

public class fila extends lista{
	private no ultimo;
	
	public void add(int num) {
		no novo = ultimo;
		ultimo= new no();
		ultimo.setNum(num);
		ultimo.setP(null);
		if(super.primeiro == null) {
			super.primeiro=ultimo;
		}else {
			novo.setP(ultimo);
		}
		
	}
	
	public void remover() {
		super.primeiro = super.primeiro.getP();
	}
}
