package ChainOfResponsibility;

public class Processor {
	private Processor processor;
	 
    public Processor(Processor processor){
        this.processor = processor;
    };
     
    public void process(Texto txt){
        if(processor != null)
            processor.process(txt);
    };
}
