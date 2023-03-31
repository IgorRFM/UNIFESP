package AbstractFactory;

public class Triangulo implements Fig {
	public Ponto t1,t2,t3;

	public Triangulo(Ponto t1, Ponto t2, Ponto t3) {
		this.t1=t1;
		this.t2=t2;
		this.t3=t3;
		
		System.out.println("\nRetangulo contruído com as extremidades t1("+t1.getX()+", "+t1.getY()+"), t2( "+t2.getX()+","+t2.getY()+") e t3("+t3.getX()+","+t3.getY()+" )");
	}


	@Override
	public void draw() {
		System.out.println("\nTriangulo");
		
	}
}
