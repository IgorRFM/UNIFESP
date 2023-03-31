package lista1;

public class ramo extends mortal{
	private ramo esq, dir;
	private int valor=0;
	
	public void setValor(int valor) {
		this.valor=valor;
	}
	
	public ramo() {
		this.esq = null;
		this.dir = null;
	}
	
	public ramo(ramo esq, ramo dir) {
		this.esq = esq;
		this.dir = dir;
	}
	
	public void printar() {
		if (this.esq != null) {
			System.out.println(this.esq.isVivo() + " ");
        }
        
        if (this.dir != null) {
    		System.out.println(this.dir.isVivo() + " ");

        }
		System.out.println(this.isVivo() + "\n");
	}

	public void mata() {
		if (this.esq != null) {
            this.esq.mata();
        }
        
        if (this.dir != null) {
            this.dir.mata();
        }
        super.mata();
	}
	
	public String toString() {
		String resp="";
		this.printar();
		return resp;
		
	}
}
