public class Pessoa {
    String nome;
    double altura;
    double peso;

    public Pessoa(){
        nome = "Fulano";
        altura = 1.80;
        peso = 80.0;
    }
    public Pessoa(String nome, double altura, double peso){
        this.nome = nome;
        this.altura = altura;
        this.peso = peso;
    }
    // Fim Atv 2
    public double calcularIMC(){
        double IMC = peso / (altura*altura);
        return IMC;
    }
    // Fim Atv 3
    public String classificacaoIMC(){
        if(calcularIMC() < 18.5) return "Magreza";
        else if(calcularIMC() < 25.0) return "Normal";
        else if(calcularIMC() < 30.0) return "Sobrepeso";
        else if(calcularIMC() < 35.0) return "Obesidade grau I";
        else if(calcularIMC() < 40.0) return "Obesidade grau II";
        else return "Obesidade grau III";
    }
    // Fim Atv 4
}
