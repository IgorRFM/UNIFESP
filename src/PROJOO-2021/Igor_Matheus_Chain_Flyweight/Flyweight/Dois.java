package Flyweight;

public class Dois implements Numeros {
	public int alagarismo;

	@Override
	public void algarismo() {
		// TODO Auto-generated method stub
		this.alagarismo=2;
		System.out.print(this.alagarismo);
	}

	protected int getAlagarismo() {
		return alagarismo;
	}

}
