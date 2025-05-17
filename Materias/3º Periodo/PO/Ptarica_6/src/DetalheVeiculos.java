public class DetalheVeiculos  {
    private Veiculo[] veiculos;

    public DetalheVeiculos(Veiculo[] veiculos){
        this.veiculos = veiculos;
    }

    public void printVeiculos(){
        for (Veiculo veiculo : veiculos){
            if(veiculo instanceof Carro){
                System.out.printf("Carro: %s - %s - %d", veiculo.getPlaca(), veiculo.getCor(), ((Carro) veiculo).getRodas());
            }else if(veiculo instanceof Moto){
                System.out.printf("Moto: %s - %s - %d", veiculo.getPlaca(), veiculo.getCor(), ((Moto) veiculo).getRodas());
        }
    }
}