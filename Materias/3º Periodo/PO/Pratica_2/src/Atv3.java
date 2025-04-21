import java.util.Scanner;

public class Atv3 {
    public static void main(String args[]){
        Scanner entrada = new Scanner(System.in);
        int[] b = new int[3];
        int maior = 0;
        
        for(int i=0; i<3; i++){
            b[i] = entrada.nextInt();
            if(maior<b[i]){
                maior = b[i];
            }else;
        }
        
        System.out.println(maior);
        
    }
}
