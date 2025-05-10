public class Aluno {
    String nome;
    int idade;
    char genero;
    long ra;

    public Aluno(){
        nome = "Aluno";
        idade = 18;
        genero = 'M';
        ra = 123456789;
    }
    public Aluno(String nome, int idade){
        this.nome = nome;
        this.idade = idade;
        genero = 'M';
        ra = 123456789;
    }
    public Aluno(String nome, char genero, long ra){
        this.nome = nome;
        idade = 18;
        this.genero = genero;
        this.ra = ra;
    }
    public void print(){
        System.out.printf("%s - %d - %c", nome, idade, genero);
    }
    //Fim Atv 1

    public Aluno(String nome, int idade, char genero){
        this.nome = nome;
        this.idade = idade;
        this.genero = genero;
    }

    public String getNome(){
        return nome;
    }   
    public void setNome(String nome){
        this.nome = nome;
    }
    public int getIdade(){
        return idade;
    }
    public void setIdade(int idade){
        this.idade = idade;
    }
    public char getGenero(){
        return genero;
    }
    public void setGenero(char genero){
        this.genero = genero;
    }
}

