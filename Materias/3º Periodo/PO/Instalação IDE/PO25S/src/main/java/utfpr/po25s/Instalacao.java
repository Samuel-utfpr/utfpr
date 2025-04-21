/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package utfpr.po25s;

/**
 *
 * @author samue
 */
import java.util.Scanner;
public class Instalacao {
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
    
