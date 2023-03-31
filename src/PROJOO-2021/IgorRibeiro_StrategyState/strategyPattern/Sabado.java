package strategyPattern;

public class Sabado implements Strategy {
	@Override
	public void queDia() {
		System.out.println("Sábado.");
	}

}
