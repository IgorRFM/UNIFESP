package strategyPattern;

public class Context {
	private Strategy strategy;
	
	public Context(Strategy strategy) {
		this.strategy=strategy;
	}
	public void diaSemana() {
		strategy.queDia();
	}
}
