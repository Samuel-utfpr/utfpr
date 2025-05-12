public class Cliente extends Pessoa{
    private double limiteCompra;

    public double getLimiteCompra() {
        return limiteCompra;
    }
    public void setLimiteCompra(double limiteCompra) {
        this.limiteCompra = limiteCompra;
    }
    
    public Cliente(String nome, String endereco, double limiteCompra) {
        super(nome, endereco);
        this.limiteCompra = limiteCompra;
    }
}
