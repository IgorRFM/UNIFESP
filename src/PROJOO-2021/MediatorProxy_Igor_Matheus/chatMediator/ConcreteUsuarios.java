package chatMediator;

public class ConcreteUsuarios extends Usuarios {

	public ConcreteUsuarios(Mediator chat, String nome) {
		super(chat, nome);
		// TODO Auto-generated constructor stub
	}

	@Override
	protected void receive(String msg, Usuarios autor) {
		System.out.println(this.nome + ": Mensagem recebida do usuário " + autor.nome +":" + msg + "\n");

		
	}

	@Override
	public void send(String msg) {
		System.out.println(this.nome + ": Enviando a mensagem =" + msg +"\n");
		chat.sendMessage(msg, this);
		
	}

}
