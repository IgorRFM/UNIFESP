package lista1;

public class gato extends mortal{
	
	private int vidas=6;
	
	public void mata() {
		if(vidas == 0) {
			super.mata();
		}else {
			vidas--;
		}
	}
	
	public String toString() {
		String resp="";
		int temp = vidas+1;
		if(this.isVivo())
			resp+="O gato está vivo com " + temp + " vidas restantes";
		else
			resp+= "O gato está morto";
		return resp;
		
	}

}
