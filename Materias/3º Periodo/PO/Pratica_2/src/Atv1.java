import java.util.Scanner;

public class Atv1 {
    public static void main(String args[]){
        Scanner entrada = new Scanner(System.in);
        double[] b = new double[4];
        double soma = 0;
        for(int i=0; i<4; i++){
            b[i] = entrada.nextDouble();
            soma = soma + b[i];
            
        }
        double med = soma / 4;
        
        System.out.println(med);
        
    }
}
