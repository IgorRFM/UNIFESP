package Flyweight;

import java.util.Random;

public class Main {

	public static void main(String[] args) {
		
		Numeros n;
		
		for(int i=0; i<10; i++) {
			System.out.println("__Criando o número aleatório " + i + "__\n");
			for(int j=0; j<10; j++) {
				Random r = new Random();
				n = FabricaDeNum.getNum(r.nextInt(10-0) + 0);
				n.algarismo();
			}
			System.out.println("\n\nT");
		}

	}

}
