#include<stdio.h>
#include<stdbool.h>
#define TAM 10


typedef struct{
    int vetor[TAM];
    int topo;
} pilhaEstatica;

void iniciaPilhaEstatica(pilhaEstatica *p){
    p->topo = 0;
}

bool estaVaziaPilhaEstatica(pilhaEstatica *p){
    return (p->topo == 0);
}

bool estaCheiaPilhaEstatica(pilhaEstatica *p){
    return (p->topo == TAM);
}

void inserirPilhaEstatica(pilhaEstatica *p, int valor){
    if(!estaCheiaPilhaEstatica(p)){
        p->vetor[p->topo] = valor;
        p->topo++;
    }else{
        printf("warning: Pilha Cheia\n");
    }
}

void imprimirPilhaEstatica(pilhaEstatica *p){
    printf("Pilha Estatica: \n");
    printf("Pilha = [ ");
    int i;
    for(i = 0;i<p->topo;i++){
        printf("%d ", p->vetor[i]);
    }
    printf(" ]\n");

}

void removerPilhaEstatica(pilhaEstatica *p){
    if(!estaVaziaPilhaEstatica(p)){
        p->topo--;
    }
}

int main(){
    int i;
    int elementos[] = {4, 7, 8, 10, 12};
    pilhaEstatica pilha;
    iniciaPilhaEstatica(&pilha);
    for(i=0;i<6;i++){
        inserirPilhaEstatica(&pilha, elementos[i]);
        imprimirPilhaEstatica(&pilha);
    }
    for(i=0;i<6;i++){
        removerPilhaEstatica(&pilha);
        imprimirPilhaEstatica(&pilha);
    }

}