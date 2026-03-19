#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void inicializaTabela(int t[]){
    int i;
    for(i=0; i<TAM; i++){
        t[i] = -1;
    }

}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir(int t[], int valor){
    int id = funcaoHash(valor);
    while(t[id] != -1){
        id = funcaoHash(id + 1);
    }
    t[id] = valor;
}

void imprimirTabela(int t[]){
    int i;
    for(i=0; i<TAM; i++){
        if(t[i] != -1){
            printf("Posicao %d: %d\n", i, t[i]);
        } else {
            printf("Posicao %d: Vazia\n", i);
        }
    }
}

int main(){
    int tabela[TAM];
    inicializaTabela(tabela);

    //inserindo valores 17, 23, 51, 64, 35, 92
    inserir(tabela, 17);
    inserir(tabela, 23);
    inserir(tabela, 51);
    inserir(tabela, 64);
    inserir(tabela, 35);
    inserir(tabela, 92);

    imprimirTabela(tabela);
    
    return 0;
}