package vetoresetc;

public class Cat {
    private int catNumber;
    
    public Cat(int i) { 
    	catNumber = i;
    }
    
    public void id() {
        System.out.println("Cat #" + catNumber);
    }
}