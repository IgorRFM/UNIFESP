package lista2;
public class RoboSimples extends RoboAbstrato {
	RoboSimples(String n, int px, int py, short d) {
		super(n, px, py, d);
	}
	public void move(int passos) {
		switch (direcaoAtual()) {
			case 0:
				moveX(+passos);
				break;
			case 90:
				moveY(+passos);
				break;
			case 180:
				moveX(-passos);
				break;
			case 270:
				moveY(-passos);
				break;
		}
	}
	
	public void mudaDirecao(short novaDir) {
		if(novaDir < 45 || novaDir > 315) {
			super.mudaDirecao((short) 0);
		}else if(novaDir >=45 || novaDir <=135) {
			super.mudaDirecao((short) 90);
		}else if(novaDir >=135 || novaDir <=225) {
			super.mudaDirecao((short) 180);
		}else if(novaDir >=225 || novaDir <=315) {
			super.mudaDirecao((short) 270);
		}
		
	}
}



