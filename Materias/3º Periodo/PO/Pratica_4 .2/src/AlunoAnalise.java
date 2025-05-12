
public class AlunoAnalise {
    Aluno alunos[];

    public AlunoAnalise(Aluno[] alunos){
        for(int i = 0; i < alunos.length; i++){
            this.alunos = alunos;
        }
    }

    public void listarAlunosPorGenero(char genero){
        for(int i = 0; i < alunos.length; i++){
            if(alunos[i].getGenero() == genero){
                alunos[i].print();
            }
        }
    }

    public void listarAlunoMaisVelho(){
        int maisVelho = 0;
        for(int i = 1; i < alunos.length; i++){
            if(alunos[i].getIdade() > alunos[maisVelho].getIdade()){
                maisVelho = i;
            }
        }
        alunos[maisVelho].print();
    }

    public void listarAlunoMaisJovem(){
        int maisNovo = 0;
        for(int i = 1; i < alunos.length; i++){
            if(alunos[i].getIdade() < alunos[maisNovo].getIdade()){
                maisNovo = i;
            }
        }
        alunos[maisNovo].print();
    }

    public double getMediaIdade(){
        double soma = 0;
        for(int i = 0; i < alunos.length; i++){
            soma += alunos[i].getIdade();
        }
        return soma / alunos.length;
    }
    
}
