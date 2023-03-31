package AbstractFactory;

public abstract class FigurasAbstract {
	private Figura f=null;
	
	abstract Fig getShape(String forma, double  a, double b);

	FigurasAbstract(Figura f){
		this.f = f;
	}
}
