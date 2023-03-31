package chatMediator;

import java.util.ArrayList;
import java.util.List;

public class ConcreteMediator implements Mediator {
	private List<Usuarios> users;
	

	public ConcreteMediator()
	{
			this.users = new ArrayList<Usuarios>();
	}

	@Override
	public void sendMessage(String msg, Usuarios user) {
		for( Usuarios u : this.users )
		{
				if(u != user)
				{
						u.receive(msg, user);
				}
		}
		
	}

	@Override
	public void addUser(Usuarios user) {
		this.users.add(user);
		
	}


}
