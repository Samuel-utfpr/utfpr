#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct No{
    int valor;
    struct No* esq;
    struct No* dir;
} No;

No* NovoNo(int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int valor){
    if(raiz == NULL) raiz = NovoNo(valor);
    if(valor < (raiz)->valor){
        raiz->esq = inserir(raiz->esq, valor);
    } else if(valor > (raiz)->valor){
        raiz->dir = inserir(raiz->dir, valor);
    } return raiz;
}

int buscar(No* raiz, int valor){
    if(raiz == NULL) return 0;
    if(raiz->valor == valor) return 1; 
     else if(valor < raiz->valor){
        return buscar(raiz->esq, valor);
    } else {
        return buscar(raiz->dir, valor);
    }
}

void emOrdem(No* raiz){
    if(raiz != NULL){
        emOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        emOrdem(raiz->dir);
    }
}

double medirBusca(No* raiz, int valor, int repeticoes){
    clock_t inicio = clock();
    for(int r = 0; r < repeticoes; r++){
        buscar(raiz, valor);
    }
    clock_t fim = clock();
    double segundos = (double)(fim - inicio) / CLOCKS_PER_SEC;
    return segundos; 

}

int main(){
    No* ArvoreA = NULL;
    No* ArvoreB = NULL;
    int valoresA[7] = {50, 30, 70, 20, 40, 60, 80};
    int valoresB[7] = {10, 20, 30, 40, 50, 60, 70};
    for(int i = 0; i < 7; i++){
        ArvoreA = inserir(ArvoreA, valoresA[i]);
        ArvoreB = inserir(ArvoreB, valoresB[i]);
    }

    while (1){
    int opcao;
    printf("Escolha a opcao de busca:\n");
    printf("1 - Informar valores a ser buscados\n");
    printf("2 - Realizar Buscas dos proprios valores inseridos\n");
    printf("3 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case (1):{
            int n;
            printf("Quantos valores deseja buscar? ");
            scanf("%d", &n);
            int valoresBusca[n];
            for(int i = 0; i < n; i++){
                printf("Digite o valor %d: ", i + 1);
                scanf("%d", &valoresBusca[i]);
            }
            int vezes;
            printf("Digite quantas vezes deseja repetir a busca para medir o tempo: \n");
            scanf("%d", &vezes);
            for(int i = 0; i < n; i++){
                double tempoA = medirBusca(ArvoreA, valoresBusca[i], vezes);
                double tempoB = medirBusca(ArvoreB, valoresBusca[i], vezes);
                printf("Valor %d - Tempo de busca na Arvore A (balanceada): %fl segundos\n", valoresBusca[i], tempoA);
                printf("Valor %d - Tempo de busca na Arvore B (desbalanceada): %fl segundos\n", valoresBusca[i], tempoB);
            }
        }break;

    case (2):{
            int vezes;
            int ValoresAeB[9] = {10, 20, 30, 40, 50, 60, 70, 80};
            printf("Digite quantas vezes deseja repetir a busca para medir o tempo: \n");
            scanf("%d", &vezes);
            for(int i = 0; i < 8; i++){
                double tempoA = medirBusca(ArvoreA, ValoresAeB[i], vezes);
                double tempoB = medirBusca(ArvoreA, ValoresAeB[i], vezes);
                printf("Valor %d - Tempo de busca na Arvore A (balanceada): %fl segundos\n", ValoresAeB[i], tempoA);
                printf("Valor %d - Tempo de busca na Arvore B (desbalanceada): %fl segundos\n", ValoresAeB[i], tempoB);
            }
        }break;
    case (3): exit(0);
    default: break;
    }
    }
}