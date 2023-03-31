package exercicioTriangulo;

public class contador {
	int vInicial, cont, inc, dec;
	
	public int getCont() {
		return cont;
	}

	public void setCont(int cont) {
		this.cont = cont;
	}

	public contador() {
		vInicial = 0;
		this.cont = 0;
	}
	
	public contador (int valor) {
		vInicial = valor;
		this.cont = vInicial;
	}
	
	public void incrementar() {
		this.cont++;
	}
	
	public void incrementar(int valor) {
		this.cont += valor;
	}
	
	public void decrementar() {
		this.cont--;
	}
	
	public void decrementar(int valor) {
		this.cont -= valor;
	}
	
	public static void main(String[] args) {
		contador c1 = new contador();
		System.out.println(c1.getCont());
		c1.incrementar();
		System.out.println(c1.getCont());
		c1.incrementar(5);
		System.out.println(c1.getCont());
		c1.decrementar();
		System.out.println(c1.getCont() + "\n\n");
		
		contador c2 = new contador(10);
		System.out.println(c2.getCont());
		c2.decrementar();
		System.out.println(c2.getCont());
		c2.decrementar(8);
		System.out.println(c2.getCont());


	}

}
