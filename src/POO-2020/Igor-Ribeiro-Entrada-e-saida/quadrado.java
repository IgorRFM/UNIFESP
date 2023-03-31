package entradaSaida;

public class quadrado {
	int lado, area, perimetro;

	public int getLado() {
		return lado;
	}

	public void setLado(int lado) {
		this.lado = lado;
	}

	public int getArea() {
		setArea(this.lado*this.lado);
		return area;
	}

	public void setArea(int area) {
		this.area = area;
	}

	public int getPerimetro() {
		setPerimetro(this.lado * 4);
		return perimetro;
	}

	public void setPerimetro(int perimetro) {
		this.perimetro = perimetro;
	}
	
	
}
