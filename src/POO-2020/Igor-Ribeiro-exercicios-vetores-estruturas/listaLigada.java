package vetoresetc;

public class listaLigada {
	public no raiz;
	private int tam;
	
	public listaLigada() {
		raiz = null;
		tam = 0;
	}
	
	public int tamanho() {
        return tam;
    }
	
	public void inserir(int dado) {
		no temp = new no(dado, null);
		no p;
		if(this.raiz == null) {
			this.raiz = temp;
		}else {
			p =raiz;
			while(p.getProx()!=null) {
				p = p.getProx();
			}
			p.setProx(temp);
			
		}
		this.tam++;
	}
	
	no busca(int pos) {
        if(pos >= 0 && pos < this.tam) {
            no p = this.raiz;
            
            for(int i = 0; i < pos; i++) {
                p = p.getProx();
            }
            return p;
        }
        return null;
    }
	
	public void remove(int pos) {
        no atual = busca(pos);
        
        if(atual != null) {
            no anterior= busca(pos - 1);
            anterior.setProx(atual.getProx());
        }   
 
        this.tam--;
    }
	
	public int soma() {
        int soma = 0;
        for(no p = this.raiz; p != null; p = p.getProx())
            soma += p.getDado();
        
        return soma;
    }
    
    public listaLigada inverterLista() {
        listaLigada l = new listaLigada();
        for(int i = this.tamanho() - 1; i >= 0; i--) {
            l.inserir(this.busca(i).getDado());
        }
        return l;
    }
    
    public void imprimir() {
    	no p = this.raiz;

        String str = "";
        
        while(p.getProx() != null) {
            str += p.getDado() + " | ";
            p = p.getProx();
        }
        str += p.getDado();
        System.out.println(str);
    }
    
	
}
