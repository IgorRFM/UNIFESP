package padraoBuilder;

public class Empresa {
    private Pessoa responsavel;
    
    public Empresa(String nome, int id) {
    	responsavel = new Pessoa();
    	responsavel.setId(id).setName(nome);
    	
    }
  
    public void verifica()
    {
        System.out.println("Empresa criada sob o responsável " + responsavel.toString());
    }
}
