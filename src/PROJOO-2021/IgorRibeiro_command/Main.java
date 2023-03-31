package decorator;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String txt = "Lorem Ipsum";
		
		Texto t1 = new Caps(txt);
		t1.formatar();
		System.out.println(t1.getTexto()+"\n");
		
		Texto t2 = new Tag(txt);
		t2.formatar();
		System.out.println(t2.getTexto()+"\n");
		
		Texto t3 = new Inv(txt);
		t3.formatar();
		System.out.println(t3.getTexto()+"\n");
		
		Texto t = new Caps(txt);
		t.formatar();
		t= new Inv(t.getTexto());
		t.formatar();
		t=new Tag(t.getTexto());
		t.formatar();
		System.out.println(t.getTexto()+"\n");
		
	}

}
