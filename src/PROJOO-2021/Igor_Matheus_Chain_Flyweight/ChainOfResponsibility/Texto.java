package ChainOfResponsibility;

public class Texto {
	 private String texto;
	 private int spaces, a, dots;
	 
	    public Texto(String texto)
	    {
	        this.texto = texto;
	        this.spaces =0;
	        this.a=0;
	        this.dots=0;
	    }
	 
	    public String getTexto()
	    {
	        return texto;
	    }
		protected int getSpaces() {
			return spaces;
		}

		protected void setSpaces(int spaces) {
			this.spaces = spaces;
		}

		protected int getA() {
			return a;
		}

		protected void setA(int a) {
			this.a = a;
		}

		protected int getDots() {
			return dots;
		}

		protected void setDots(int dots) {
			this.dots = dots;
		}

		protected void setTexto(String texto) {
			this.texto = texto;
		}
}
