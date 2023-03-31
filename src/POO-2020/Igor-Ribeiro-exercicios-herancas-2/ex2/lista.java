package lista;

public class lista {
	public no primeiro;
	public void criar() {
		primeiro=null;
	}
	
	public void print(){
		for(no n=primeiro; n!=null; n=n.getP()) {
			System.out.println(n.getNum());
		}
	}
	
	public void add(int num) {
		no novo = new no();
		novo.setNum(num);
		novo.setP(primeiro);
		
		primeiro = novo;
	}
	public no procurar(int num) {
		for(no n=primeiro; n!=null; n=n.getP()) {
			if(n.getNum()==num) {
				return n;
			}
		}
		return null;
	}
	public int tamanho() {
		if(primeiro == null) {
			return 0;
		}else {
			int i=0;
			for(no n=primeiro; n!=null; n=n.getP()) {
				i++;
			}
			return i;
		}
		
	}
	
}
