package Flyweight;

public class Nove implements Numeros {
	public int alagarismo;

	@Override
	public void algarismo() {
		// TODO Auto-generated method stub
		this.alagarismo=9;
		System.out.print(this.alagarismo);
	}

	protected int getAlagarismo() {
		return alagarismo;
	}

}