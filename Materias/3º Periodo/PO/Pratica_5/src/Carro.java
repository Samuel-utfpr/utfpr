public class Carro extends Veiculo{
    private int numerodeportas;
    private int potenciadomotor;

    public int getNumeroDePortas() {
        return numerodeportas;
    }
    public void setNumeroDePortas(int numerodeportas) {
        this.numerodeportas = numerodeportas;
    }
    public int getPotenciaMotor() {
        return potenciadomotor;
    }
    public void setPotenciaMotor(int potenciadomotor) {
        this.potenciadomotor = potenciadomotor;
    }
    public void printInformacoes(){
        System.out.printf("Renavam: %d, Placa: %s, Cor: %s, NumeroDePortas: %d, PotenciaMotor: %d", getRenavam(), getPlaca(), getCor(), getNumeroDePortas(), getPotenciaMotor());

    }

}
