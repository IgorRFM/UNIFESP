package Flyweight;

public class Oito implements Numeros {
	public int alagarismo;

	@Override
	public void algarismo() {
		// TODO Auto-generated method stub
		this.alagarismo=8;
		System.out.print(this.alagarismo);
	}

	protected int getAlagarismo() {
		return alagarismo;
	}

}
