package padraoBuilder;

final class Pessoa {
    // instance fields
    private int id;
    private String name;
  
    // Setter Methods
    // Note that all setters method
    // return this reference
    public Pessoa setId(int id)
    {
        this.id = id;
        return this;
    }
  
    public Pessoa setName(String name)
    {
        this.name = name;
        return this;
    }
  
    @Override
    public String toString()
    {
        return "id = " + this.id + ", name = " + this.name;
    }
}
