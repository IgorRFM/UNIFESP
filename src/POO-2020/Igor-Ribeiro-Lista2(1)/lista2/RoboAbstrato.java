package lista2;

public abstract class RoboAbstrato {
	private String nome;
	private int posicaoXAtual, posicaoYAtual;
	private short direcao;
	
	RoboAbstrato(String n, int px, int py, short d) {
		nome = n;
		posicaoXAtual = px;
		posicaoYAtual = py;
		direcao = d;
	}
	
	public void move() {
		move(1);
	}
	public abstract void move(int passos);
	public void moveX(int passos) {
		posicaoXAtual += passos;
	}
	public void moveY(int passos) {
		posicaoYAtual += passos;
	}
	public void mudaDirecao(short novaDir) {
		direcao = novaDir;
	}
	public short direcaoAtual() {
		return direcao;
	}
	public String toString() {
		String resultado = "Nome do rob�:" + nome + "\n";
		resultado = resultado + "Posi��o do rob�: (" + posicaoXAtual + "," + posicaoYAtual + ")\n";
		resultado = resultado + "Dire��o do rob�:" + direcao;
		return resultado;
	}
}
