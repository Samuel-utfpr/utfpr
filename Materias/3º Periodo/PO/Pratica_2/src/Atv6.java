import java.util.Scanner;

public class Atv6 {
    public static void main(String args[]){
        Scanner entrada = new Scanner(System.in);
        int[] b = new int[10];
        int i = 0, soma =0;
        
        do{
            b[i] = entrada.nextInt();
            i++;
        } while(b[i-1]>=0);
        for(int c=0;c<i-1;c++){
            soma += b[c];
        }
        System.out.println("Quantidade = "+i+"\nSoma = "+soma);
        
        
    }
}
