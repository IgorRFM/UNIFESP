package Flyweight;

import java.util.HashMap;

public class FabricaDeNum {
	private static HashMap<Integer, Numeros> hm = new HashMap<Integer, Numeros>();
	
	public static Numeros getNum(int id)
    {
        Numeros n = null;
  
        /* If an object for TS or CT has already been
           created simply return its reference */
        if (hm.containsKey(id))
                n = hm.get(id);
        else
        {
            /* create an object of TS/CT  */
            switch(id)
            {
            case 1:
                //System.out.println("Algarismo 1 criado.");
                n = new Um();
                break;
            case 2:
            	//System.out.println("Algarismo 2 criado.");
                n = new Dois();
                break;
            case 3:
                //System.out.println("Algarismo 3 criado.");
                n = new Tres();
                break;
            case 4:
            	//System.out.println("Algarismo 4 criado.");
                n = new Quatro();
                break;
            case 5:
                //System.out.println("Algarismo 5 criado.");
                n = new Cinco();
                break;
            case 6:
            	//System.out.println("Algarismo 6 criado.");
                n = new Seis();
                break;
            case 7:
                //System.out.println("Algarismo 7 criado.");
                n = new Sete();
                break;
            case 8:
            	//System.out.println("Algarismo 8 criado.");
                n = new Oito();
                break;
            case 9:
                //System.out.println("Algarismo 9 criado.");
                n = new Nove();
                break;
            case 0:
            	//System.out.println("Algarismo 10 criado.");
                n = new Zero();
                break;
            default :
                System.out.println("Unreachable code!");
            }
  
            // Once created insert it into the HashMap
            hm.put(id, n);
        }
        return n;
    }
	
}
