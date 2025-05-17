public class Aluno extends Pessoa {
    private int ra;
    private String diciplinas;

    public int getRa() {
        return ra;
    }
    public void setRa(int ra) {
        this.ra = ra;
    }
    public String getDiciplinas() {
        return diciplinas;
    }
    public void setDiciplinas(String diciplinas) {
        this.diciplinas = diciplinas;
    }
    public Aluno(String nome, int idade, int ra, String diciplinas) {
        super(nome, idade);
        this.ra = ra;
        this.diciplinas = diciplinas;
    }

    public String retornaDados() {
        return super.retornaDados() + " -- " + ra + " -- " + diciplinas;
    }
}
