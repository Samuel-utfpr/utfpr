import java.util.Scanner;

public class Atv8 {
    public static void main(String args[]){
        Scanner entrada = new Scanner(System.in);
         int i1=0, i2=0, i3=0, i4=0;
        while(true){
            int valor = entrada.nextInt();
            if(valor < 0) break;
            else if(valor <= 25) i1++;
            else if(valor > 25 && valor <= 50) i2++;
            else if(valor > 50 && valor <= 75) i3++;
            else if(valor > 75 && valor <= 100) i4++;
        }
        System.out.println("[0,25] = "+i1);
        System.out.println("[26,50] = "+i2);
        System.out.println("[51,75] = "+i3);
        System.out.println("[76,100] = "+i4);
    }
}
