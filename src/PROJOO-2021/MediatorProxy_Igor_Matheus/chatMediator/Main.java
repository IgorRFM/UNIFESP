package chatMediator;

public class Main {

	public static void main(String[] args) {
		Mediator chat = new ConcreteMediator();
		Usuarios igor = new ConcreteUsuarios(chat, "Igor");
		Usuarios Matheus = new ConcreteUsuarios(chat, "Matheus");
		Usuarios Lucas = new ConcreteUsuarios(chat, "Lucas");
		Usuarios Fabio = new ConcreteUsuarios(chat, "Fábio");
		
		
		chat.addUser(igor);
		chat.addUser(Matheus);
		chat.addUser(Lucas);
		chat.addUser(Fabio);

		Fabio.send("Bom dia a todos, pessoal. As atividades da semana já estão no classroom!");

	}

}
