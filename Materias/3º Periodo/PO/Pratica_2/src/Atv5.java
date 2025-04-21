import java.util.Scanner;

public class Atv5 {
    public static void main(String args[]){
        Scanner entrada = new Scanner(System.in);
        int numero = entrada.nextInt();
        for(int i=numero; i>=1; i--){
            System.out.print(i+" ");
        }
    }
}
