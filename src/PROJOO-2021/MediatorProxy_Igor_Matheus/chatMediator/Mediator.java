package chatMediator;

public interface Mediator {
	public abstract void sendMessage(String message, Usuarios user);
	public abstract void addUser(Usuarios user);
}
