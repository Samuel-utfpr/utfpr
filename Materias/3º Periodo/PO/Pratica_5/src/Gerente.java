public class Gerente extends Funcionario {
    private String departamento;

    public String getDepartamento() {
        return departamento;
    }
    public void setDepartamento(String departamento) {
        this.departamento = departamento;
    }

    public Gerente(String nome, String endereco, double salario, String departamento) {
        super(nome, endereco, salario);
        this.departamento = departamento;
    }

    
}
