package factoryPattern;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FigFactory FF = new FigFactory();
		FF.inicializar();
		System.out.println(FF.createFig(1).area(5)); //1=quadrado
		System.out.println(FF.createFig(2).area(5)); //2=circulo
		System.out.println(FF.createFig(3).area(5)); //3=triangulo equilátero
	}

}
