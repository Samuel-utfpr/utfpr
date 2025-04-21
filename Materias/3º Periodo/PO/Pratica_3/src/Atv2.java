public class Atv2 {
    public static int procuraMaiorValor(int vet[]){
        int maior=vet[0];
        for(int i=0; i<vet.length; i++){
            if(maior<vet[i]){
                maior = vet[i];
            }
        }
        return maior;
    }
    public static void main(String args[]){
        int vetor[] = {1,-2,3,4,-5,6,-7};
        int maior = procuraMaiorValor(vetor);
        System.out.println(maior);
    }
}
