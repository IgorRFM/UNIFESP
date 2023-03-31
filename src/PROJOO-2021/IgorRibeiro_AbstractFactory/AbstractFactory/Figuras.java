package AbstractFactory;

public class Figuras extends FigurasAbstract {

	Figuras(Figura f) {
		super(f);
		// TODO Auto-generated constructor stub
	}

	@Override
	Fig getShape(String forma, double d, double e) {
		if(forma.equalsIgnoreCase("ponto")) {
			return new Ponto(d, e);
		}
		return null;
	}

	public Fig getShape(String forma, Ponto centro, double e) {
		return new Circulo(centro, e);
	}

	public Fig getShape(String forma, Ponto r1, Ponto r2) {
		
		return new Retangulo(r1,r2);
	}

	public Fig getShape(String string, Ponto t1, Ponto t2, Ponto t3) {
		
		return new Triangulo(t1,t2,t3);
	}

}
