package vetoresetc;

import java.util.ArrayList;
import java.util.List;

public class CatAndDog {
	public static void main(String[] args) {
        List cats = new ArrayList();
        for(int i = 0; i < 7; i++)
            cats.add(new Cat(i));
        
        cats.add(new Cat(7));
        for(int i = 0; i < cats.size(); i++)
            ((Cat)cats.get(i)).id();
        }
}
