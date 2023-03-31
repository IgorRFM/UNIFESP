package ChainOfResponsibility;

public class DotProcessor extends Processor {

	public DotProcessor(Processor processor) {
		super(processor);
		// TODO Auto-generated constructor stub
	}
	
	public void process(Texto txt)
    {
    	if(txt.getDots()==0) {
    		int dots=0;
    		dots = txt.getTexto().length() - txt.getTexto().replaceAll("[.!?]+", "").length();
            System.out.println("Número de .: "+ dots+"\n");
            txt.setSpaces(dots);
            super.process(txt);	
    	}else {
    		super.process(txt);	
    	}
    }
}