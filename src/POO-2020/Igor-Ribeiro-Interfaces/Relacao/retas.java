package interfaces;

public class retas implements Relacao {
	private double[] p1 = new double[2];
	private double[] p2 = new double[2];
	
	public double tamanho() {
		
		double tam = Math.sqrt(Math.pow((p1[0] - p2[0]),2) + Math.pow((p1[1] - p2[1]),2) );
		return tam;
	}
	
	public synchronized double[] getP1() {
		return p1;
	}

	public synchronized void setP1(double[] p1) {
		this.p1 = p1;
	}

	public synchronized double[] getP2() {
		return p2;
	}

	public synchronized void setP2(double[] p2) {
		this.p2 = p2;
	}
	

	@Override
	public boolean maiorQue(retas r2) {
		if(this.tamanho() > r2.tamanho()) {
			return true;
		}else {
			
		return false;}
	}

	@Override
	public boolean menorQue(retas r2) {
		if(this.tamanho() < r2.tamanho()) {
			return true;
		}else {
			
		return false;}
	}

	@Override
	public boolean igualA(retas r2) {
		if(this.tamanho() == r2.tamanho()) {
			return true;
		}else {
			
		return false;}
	}

}
