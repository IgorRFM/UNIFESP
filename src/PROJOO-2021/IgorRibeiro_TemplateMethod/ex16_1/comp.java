package ex16_1;

import java.util.Comparator;

public class comp implements Comparator<String> {

	@Override
	public int compare(String arg0, String arg1) {
		if(arg0.charAt(arg0.length()-1) > arg1.charAt(arg1.length()-1)) return 1;
		else if(arg0.charAt(arg0.length()-1) < arg1.charAt(arg1.length()-1)) return -1;
		else return 0;
		
	}

}
