package strategyPattern;

import java.util.Calendar;
import java.util.GregorianCalendar;

public class Main{

	public static void main(String[] args) {
		GregorianCalendar gc = new GregorianCalendar();
		int index = gc.get(Calendar.DAY_OF_WEEK);
		System.out.println(index);
		
		Handler h = new Handler();
		Context c = new Context(h.diaSemana(index));
		c.diaSemana();
		
		

	}

}
