package chatMediator;

public abstract class Usuarios {
	protected Mediator chat;
	protected String nome;
	
	public Usuarios(Mediator chat, String nome) {
		this.chat = chat;
		this.nome = nome;
	}

	protected abstract void receive(String msg, Usuarios autor);
	public abstract void send( String msg );

	
	
	
}
