package vetoresetc;

public class Dog {
    private int dogNumber;
    
    public Dog(int i) { 
    	dogNumber = i; 
    }
    public void id() {
        System.out.println("Dog #" + dogNumber);
    }
}