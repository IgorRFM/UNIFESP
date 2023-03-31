package vetoresetc;

public class ex9 {

	public static void main(String[] args) {
		
        pilha p = new pilha();
        
        p.push("igor");
        p.push("Yuri");
        
        System.out.println("Topo: " + p.top() + "\n");
        p.pop();
        
        System.out.println("Topo: " + p.top() + "\n");
        
        p.push("josé");
        p.push("christina");
        
        System.out.println(p);
        System.out.println("Topo: " + p.top() + "\n");

	}

}
