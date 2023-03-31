package lista2;

public class RoboPesadoABateria extends RoboABateria {
	private double peso;
	RoboPesadoABateria(String n, int px, int py, short d, long e) {
		super(n, px, py, d, e);
		// TODO Auto-generated constructor stub
	}
	
	public void move(int passos) {
		long energiaASerGasta;
		if(direcaoAtual() == 45 || direcaoAtual() == 135 || direcaoAtual() == 225 || direcaoAtual() == 315) {
			energiaASerGasta = (long) (passos * 1.4 * peso);
		}else {
			energiaASerGasta = (long) (passos * peso);
			}
		
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
