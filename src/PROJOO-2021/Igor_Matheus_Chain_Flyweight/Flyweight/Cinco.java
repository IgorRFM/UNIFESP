package Flyweight;

public class Cinco implements Numeros {
	public int alagarismo;

	@Override
	public void algarismo() {
		// TODO Auto-generated method stub
		this.alagarismo=5;
		System.out.print(this.alagarismo);
	}

	protected int getAlagarismo() {
		return alagarismo;
	}

}
