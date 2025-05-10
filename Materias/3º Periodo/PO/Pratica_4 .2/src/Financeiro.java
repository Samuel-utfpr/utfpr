public class Financeiro {
    Lancamento lancamentos[];
    public void processarLancamento(Lancamento lancamento){
        for(int i = 0; i < lancamentos.length; i++){
            if(lancamento.getTipo() == 'Receber'){
                System.out.println("Lançamento de crédito: " + lancamento.getValor());
            } else if(lancamento.getTipo() == 'Pagar'){
                System.out.println("Lançamento de débito: " + lancamento.getValor());
            } else {
                System.out.println("Tipo de lançamento inválido");
            }
        }
    }
    
}
