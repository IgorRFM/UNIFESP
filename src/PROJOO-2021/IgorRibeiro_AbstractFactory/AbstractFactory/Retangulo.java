package AbstractFactory;

public class Retangulo implements Fig {
	public Ponto r1,r2;

	public Retangulo(Ponto r1, Ponto r2) {
		this.r1=r1;
		this.r2=r2;
		
		System.out.println("\nRetangulo contruído com as extremidades r1("+r1.getX()+", "+r1.getY()+") e r2( "+r2.getX()+","+r2.getY()+")");

	}

	@Override
	public void draw() {
		System.out.println("\nRetangulo");
		
	}

}
