package lista1;

public class testes {

	public static void main(String[] args) {
		mortal ser = new mortal();
		System.out.println(ser.isVivo());
		ser.mata();
		System.out.println(ser.isVivo()+"\n\n");

		gato g = new gato();
		System.out.println(g.isVivo());
		g.mata();
		System.out.println(g.isVivo());
		g.mata();
		g.mata();
		g.mata();
		g.mata();
		g.mata();
		g.mata();
		System.out.println(g.isVivo()+"\n\n");
		
		
		ramo esq = new ramo();
		esq.setValor(10);
		ramo dir = new ramo();
		dir.setValor(20);
		ramo raiz = new ramo(esq, dir);
		raiz.setValor(15);
		
		raiz.printar();
		
		raiz.mata();
	
		raiz.printar();
		
		System.out.println(g.toString());
		System.out.println(raiz.toString());
		
		circulo c = new circulo();
		c.setArea(10.0);
		System.out.println(c.toString());
		
		paralelograma par = new paralelograma();
		par.setArea(11, 12);
		System.out.println(par.toString());
		
		retangulo ret = new retangulo();
		ret.setArea(13, 14);
		System.out.println(ret.toString());
		
		quadrado q = new quadrado();
		q.setArea(15);
		System.out.println(q.toString());
		
		losango l = new losango();
		l.setArea(16,17);
		System.out.println(l.toString());
		
		triangulo t = new triangulo();
		t.setArea(18, 19);
		System.out.println(t.toString());
		
		triangulo tr = new triangulo();
		tr.setArea(20, 21);
		System.out.println(tr.toString());

		
	}

}
