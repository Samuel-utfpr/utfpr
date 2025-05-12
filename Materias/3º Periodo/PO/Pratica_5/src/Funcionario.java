public class Funcionario extends Pessoa{
    private double salario;

    public double getSalario() {
        return salario;
    }
    public void setSalario(double salario) {
        this.salario = salario;
    }

    public Funcionario(String nome, String endereco, double salario) {
        super(nome, endereco);
        this.salario = salario;
    }
 
    
}
