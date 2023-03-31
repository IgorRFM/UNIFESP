package ChainOfResponsibility;

public class AProcessor extends Processor {

	public AProcessor(Processor processor) {
		super(processor);
		// TODO Auto-generated constructor stub
	}
	
	public void process(Texto txt)
    {
    	if(txt.getA()==0) {
    		int a=0;
            a = txt.getTexto().length() - txt.getTexto().replaceAll("a", "").length();
            System.out.println("Número de A: "+ a+"\n");
            txt.setSpaces(a);
            super.process(txt);	
    	}else {
    		super.process(txt);	
    	}
    }

}
