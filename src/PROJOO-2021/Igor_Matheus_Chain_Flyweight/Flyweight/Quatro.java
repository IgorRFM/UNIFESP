package Flyweight;

public class Quatro implements Numeros {
	public int alagarismo;

	@Override
	public void algarismo() {
		// TODO Auto-generated method stub
		this.alagarismo=4;
		System.out.print(this.alagarismo);
	}

	protected int getAlagarismo() {
		return alagarismo;
	}

}
