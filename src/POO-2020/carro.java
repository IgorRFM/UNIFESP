/*
 * Nome: Igor Ribeiro Ferreira de Matos
 * Ra: 140492
 * 
 * */

package carro;

public class carro {
	String marca;
	String modelo;
	String placa;
	int aceleracao;
	
	public void acelerar(int a) {
		System.out.println("Acelerando o carro a " + a + " m/s²");
		this.aceleracao = a;
	}
	public void frear() {
		System.out.println("Freiando o carro.");
		this.aceleracao=0;
	}
	
	public static void main(String[] args) {
		carro c1 = new carro();
		c1.marca = "Fiat";
		c1.modelo = "UNO";
		c1.placa = "ABC-1234";
		c1.acelerar(5);
		c1.frear();
	}

}
