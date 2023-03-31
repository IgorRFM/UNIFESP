package exercicioTriangulo;
/*
 * Nome: Igor Ribeiro Ferreira de Matos
 * Ra: 140492
 * 
 * */

public class carro {
	String marca;
	String modelo;
	String placa;
	int aceleracao;
	int vezesAcelerou, vezesFreou, vezesLigou;
	boolean ligado;
	
	public void acelerar(int a) {
		System.out.println("Acelerando o carro a " + a + " m/s²");
		this.aceleracao = a;
		this.vezesAcelerou++;
	}
	public void frear() {
		System.out.println("Freiando o carro.");
		this.aceleracao=0;
		this.vezesFreou++;
	}
	
	public void ligar() {
		if(this.ligado == false) {
			ligado = true;
			this.vezesLigou++;
		}else {
			//o carro já está ligado
		}
			
	}
	
	public void desligar() {
		if(this.ligado == true) {
			ligado = false;
		}else {
			//o carro já está ligado
		}
			
	}
	
	public carro() {
		this.marca=""; this.modelo=""; this.placa="";
		this.aceleracao = 0;
		this.vezesAcelerou=0; this.vezesFreou=0; this.vezesLigou=0;
	}
	
	public void contadores() {
		System.out.println("O carro freou " + this.vezesFreou + " vezes, acelerou " + this.vezesAcelerou + " vezes e ligou " + this.vezesLigou);
	}
	
	public static void main(String[] args) {
		carro c1 = new carro();
		c1.marca = "Fiat";
		c1.modelo = "UNO";
		c1.placa = "ABC-1234";
		
		c1.ligar();
		c1.acelerar(5);
		c1.frear();
		c1.acelerar(10);
		c1.frear();
		c1.desligar();
		c1.ligar();
		c1.acelerar(10);
		c1.frear();
		c1.desligar();
		
		c1.contadores();
		
	}

}
