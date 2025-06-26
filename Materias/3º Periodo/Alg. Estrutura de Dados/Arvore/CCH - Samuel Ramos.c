#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char calculaASCIInome(char *nome) {
    int soma = 0;
    for(int i = 0; nome[i] != '\0'; i++) {
        if(nome[i] == ' ') continue;
        soma += (int)nome[i];
    }
    if(soma % 2 == 0) {
        return 'P'; 
    } else {
        return 'I';
    }
}

int esq(int i) {
    return (2 * i + 1);
}
int dir(int i) {
    return (2 * i + 2);
}

void troca(int *vetor, int a, int b) {
    int aux = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = aux;

}

inverterOrdem(int *vetor, int i, int j) {
    while(i < j) {
        troca(vetor, i, j);
        i++;
        j--;
    }
}

void maxHealpFy (int *vetor, int i, int th) {
    int e, d;
    int maior = i;
    e = esq(i);
    d = dir(i);

    if(e < th && vetor[e] > vetor[i]) {
        maior = e;
    }    
    if(d < th && vetor[d] > vetor[maior]) {
        maior = d;
    }
    if(maior != i) {
        troca(vetor, i, maior);
        maxHealpFy(vetor, maior, th);
    }
}

void BuildMaxHeap(int *vetor, int th) {
    for(int i = (th / 2) - 1; i >= 0; i--) {
        maxHealpFy(vetor, i, th);
    }
}

void HeapSort(int *vetor, int th) {
    BuildMaxHeap(vetor, th);
    for(int i = th - 1; i > 0; i--) {
        troca(vetor, 0, i);
        maxHealpFy(vetor, 0, i);
    }
}


int main(){
    char nome[100];
    int tam;
    printf("----------CCH - Samuel Ramos----------\n");
    printf("Digite seu nome completo:");
    int invalido;
    do {
        scanf("%[^\n]", nome);
        getchar();
        invalido = 0;
                for(int i = 0; nome[i] != '\0'; i++) {
                // Só aceita letras ou espaço
                    if(!((nome[i] >= 'A' && nome[i] <= 'Z') || (nome[i] >= 'a' && nome[i] <= 'z') || nome[i] == ' ')) {
                        invalido = 1;
                    }
                }
                if(invalido == 1){
                    printf("Digite apenas letras. Tente de novo:");
                }
    } while(invalido == 1);

    printf("Digite a quantidade de numeros:");
    do{
        scanf("%d", &tam);
        if(tam <= 0) {
            printf("Digite um numero maior que zero:");
        }
    } while(tam <= 0);
    
    int vetor [tam];
    printf("Digite os numeros:");
    for(int i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }
    printf("\n");

    HeapSort(vetor, tam);

    if(calculaASCIInome(nome) == 'P') {
        printf("Seu nome tem uma soma de ASCII par.\n");
        printf("Numeros ordenados em ordem crescente:");
        for(int i = 0; i < tam; i++){
            printf("%d ", vetor[i]);
        }

    } else {
        inverterOrdem(vetor, 0, tam - 1);
        printf("Seu nome tem uma soma de ASCII impar.\n");
        printf("Numeros ordenados em ordem decrescente:");
        for(int i = 0; i < tam; i++){
            printf("%d ", vetor[i]);
        }
    }
    printf("\n");
    printf("----------CCH - Samuel Ramos----------\n");
    return 0;
}