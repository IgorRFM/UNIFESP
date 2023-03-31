package lista1;

public class losango extends paralelograma{
	private double d1, d2;
	public void setArea() {
		System.out.println("Digite o construtor com as diagonais");
	}
	public void setArea(double d1, double d2) {
		this.d1=d1;
		this.d2=d2;
		super.setArea(d1/2,d2);
	}
	public String toString() {
		String resp="";
		resp+= super.toString();
		return resp;
		
	}
}
