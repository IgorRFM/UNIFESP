/*Exercício 2*/

package exception;

@SuppressWarnings("serial")
public class motorDesligadoException extends Exception{
	public motorDesligadoException(String msg) {
		super(msg);
	}
}
