package AbstractFactory;

public class Ponto implements Fig {
	public double x,y;
	
	public Ponto(double d, double e) {
		this.x = d;
		this.y=e;
		
		draw(d,e);
	}

	public void draw(double d, double e) {
		System.out.println("\nPonto construído! x: "+d+", y: "+e);
	}

	protected double getX() {
		return x;
	}

	protected void setX(double x) {
		this.x = x;
	}

	protected double getY() {
		return y;
	}

	protected void setY(double y) {
		this.y = y;
	}

	@Override
	public void draw() {
		System.out.println("\nPonto");
		
	}

}
