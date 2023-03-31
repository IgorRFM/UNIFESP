package strategyPattern;

public class Domingo implements Strategy {
	@Override
	public void queDia() {
		System.out.println("Domingo.");
	}

}
