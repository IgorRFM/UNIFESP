package factoryPattern;

import java.util.HashMap;
import java.util.Map;

public class FigFactory {
	
	Map<Integer,Figura> hm = new HashMap<Integer,Figura>();
	// 1 = quadrado
	// 2 = circulo
	// 3 = triangulo equilátero
	
	Figura q = new Quadrado();
	Figura c = new Circulo();
	Figura tr = new TriEq();
	
	public void inicializar() {
		hm.put(1, q);
		hm.put(2, c);
		hm.put(3, tr);
	}
	
	public Figura createFig(int id)
    {
		return hm.get(id);
    }

}
