public class Dependente extends Pessoa {
    private int idade;

    public int getIdade() {
        return idade;
    }
    public void setIdade(int idade) {
        this.idade = idade;
    }
    public Dependente(String nome, String endereco, int idade) {
        super(nome, endereco);
        this.idade = idade;
    }
}
