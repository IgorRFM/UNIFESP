package ChainOfResponsibility;

public class Chain {
	Processor chain;
	
	public Chain() {
		buildChain();
	}
	
	private void buildChain() {
		chain = new SpaceProcessor(new AProcessor(new DotProcessor(null)));
	}
	
	public void process(Texto txt) {
		chain.process(txt);
	}

}
