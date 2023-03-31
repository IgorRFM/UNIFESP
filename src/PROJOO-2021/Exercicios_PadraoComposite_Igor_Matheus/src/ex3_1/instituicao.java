package ex3_1;
import java.util.List;

public class instituicao extends Congresso{
	private List<Congresso> congressos;
	public instituicao(List<Congresso> congressos) {
		this.setCongressos(congressos);
	}
	public void Add(Congresso congresso) {
		this.congressos.add(congresso);
	}
	public List<Congresso> getCongressos() {
		return congressos;
	}
	public void setCongressos(List<Congresso> congressos) {

		this.congressos = congressos;
	}

	@Override
	protected void Exibir() {
		for(Congresso congresso : congressos) {
			congresso.Exibir();
		}
	}
	@Override
	protected int totalParticipantes() {
		int totalPart=0;
		for(Congresso congresso : congressos) {
			totalPart += congresso.totalParticipantes();
		}
		return totalPart;
	}
	@Override
	protected int totalAssentos() {
		int totalAssentos=0;
		for(Congresso congresso : congressos) {
			totalAssentos += congresso.totalParticipantes();
		}
		return totalAssentos;
	}

}
