public class Atv1 {

    public static int maior(int... numeros){
        int maiorN=0;
        for(int i=0; i<numeros.length; i++){
            if(numeros[i]>maiorN){
                maiorN = numeros[i];
            }
        }
        return maiorN;
    }
    public static void main(String args[]){
        double n = maior(1, 2, 3, 4);
        System.out.printf("%.1f", n);
    }
}