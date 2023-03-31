package lista2;

public class RoboComMemoria extends RoboAbstrato {
	private int passosX, passosY;
	private
	RoboComMemoria(String n, int px, int py, short d) {
		super(n, px, py, d);
	}

	@Override
	public void move(int passos) {
		switch (direcaoAtual()) {
		case 0:
			passosX+=passos;
			moveX(+passos);
			break;
		case 90:
			passosY+=passos;
			moveY(+passos);
			break;
		case 180:
			passosX-=passos;
			moveX(-passos);
			break;
		case 270:
			passosY-=passos;
			moveY(-passos);
			break;
		}	
	}
	public void retornaAOrigem() {
		moveX(-passosX);
		moveY(-passosY);
	}

}
