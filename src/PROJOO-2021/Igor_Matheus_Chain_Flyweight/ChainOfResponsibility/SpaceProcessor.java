package ChainOfResponsibility;

public class SpaceProcessor extends Processor {

	public SpaceProcessor(Processor processor) {
		super(processor);
		// TODO Auto-generated constructor stub
	}

    public void process(Texto txt)
    {
    	if(txt.getSpaces()==0) {
    		int espacos=0;
            espacos = txt.getTexto().length() - txt.getTexto().replaceAll(" ", "").length();
            System.out.println("Número de espaços: "+ espacos+"\n");
            txt.setSpaces(espacos);
            super.process(txt);	
    	}else {
    		super.process(txt);	
    	}
    }
}
