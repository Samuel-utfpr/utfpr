public class Financeiro {
    private double saldo = 0.0;
    public void processarLancamento(Lancamento lancamento){
            if(lancamento.getTipo() == 0){
                saldo -= lancamento.getValor();
                System.out.printf("Lançamento: Pagar - %s - %.2f%n", lancamento.getDescricao(), lancamento.getValor());
            } else {
                saldo += lancamento.getValor();
                System.out.printf("Lançamento: Receber - %s - %.2f%n", lancamento.getDescricao(), lancamento.getValor());
            }
    }

    public void printSaldo(){
        System.out.printf("Saldo = %.2f%n", saldo);
    }
    
}
