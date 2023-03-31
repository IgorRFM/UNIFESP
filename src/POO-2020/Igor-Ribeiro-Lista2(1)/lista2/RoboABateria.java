package lista2;

public class RoboABateria extends RoboAbstrato{
	private long energia;
	RoboABateria(String n, int px, int py, short d, long e) {
		super(n, px, py, d);
		energia = e;
	}
	public void move(int passos) {
		long energiaASerGasta = passos * 10;
		if (energiaASerGasta <= energia) {
			switch (direcaoAtual()) {
				case 0:
					moveX(+passos);
					break;
				case 45:
					moveX(+passos);
					moveY(+passos);
					break;
				case 90:
					moveY(+passos);
					break;
				case 135:
					moveY(+passos);
					moveX(-passos);
					break;
				case 180:
					moveX(-passos);
					break;
				case 225:
					moveX(-passos);
					moveY(-passos);
					break;
				case 270:
					moveY(-passos);
					break;
				case 315:
					moveY(-passos);
					moveX(+passos);
					break;
			}
			energia -= energiaASerGasta;
		}
	}
}
