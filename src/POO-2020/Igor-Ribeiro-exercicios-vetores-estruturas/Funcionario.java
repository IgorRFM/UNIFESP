package vetoresetc;

public class Funcionario {
	private String sobreNome;
	private String nome;
	private double salarioHora;
	private int anosNaEmpresa;
	
	public Funcionario(String nome, String sobrenome, double salario, int anos) {
        this.setNome(nome);
        this.setSobreNome(sobrenome);
        this.setSalarioHora(salario);
        this.setAnosNaEmpresa(anos);
    }
	
	public String getSobreNome() {
		return sobreNome;
	}
	public void setSobreNome(String sobreNome) {
		this.sobreNome = sobreNome;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public double getSalarioHora() {
		return salarioHora;
	}
	public void setSalarioHora(double salarioHora) {
		this.salarioHora = salarioHora;
	}
	public int getAnosNaEmpresa() {
		return anosNaEmpresa;
	}
	public void setAnosNaEmpresa(int anosNaEmpresa) {
		this.anosNaEmpresa = anosNaEmpresa;
	}
	
	public String toString() {
		String funcionario="";
		funcionario+="Nome: " + nome + " | Sobrenome: " + sobreNome + " | Salário hora: " + salarioHora;
		return funcionario;
		
	}
	public void imprimir(Funcionario func[], int anos) {
		for (int i = 0; i< func.length; i++) {
            if (func[i].anosNaEmpresa >= anos) {
                System.out.println(func[i].toString());
            }
        }
	}
	
}
