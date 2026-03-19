#include <stdio.h>
#include <stdlib.h>

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

// estrutura trie

typedef struct NoTrie{
    char Letra;
    struct NoTrie* filhos[26];
    int fim;
} NoTrie;

NoTrie* NovoNoTrie(char Letra){
    NoTrie* novo = (NoTrie*)malloc(sizeof(NoTrie));
    novo->Letra = Letra;
    for(int i = 0; i < 26; i++){
        novo->filhos[i] = NULL;
    }
    novo->fim = 0;
    return novo;

}

NoTrie* inserirTrie(NoTrie* raiz, const char* palavra){
    NoTrie *atual = raiz;
    for(int i = 0; palavra[i] != '\0'; i++){
        int idx = palavra[i] - 'a';
        if(atual->filhos[idx] == NULL){
            atual->filhos[idx] = NovoNoTrie(palavra[i]);
        }
        atual = atual->filhos[idx];
    }
    atual->fim = 1;

}

int buscarTrie(NoTrie* raiz, const char* palavra){
    NoTrie* atual = raiz;
    for(int i = 0; palavra[i] != '\0'; i++){
        int idx = palavra[i] - 'a';
        if(atual->filhos[idx] == NULL)return 0;
        atual = atual->filhos[idx];
    }
    return atual->fim;
}




int main(){
    NoTrie* raizTrie = NovoNoTrie('\0');
    No* Arvore = NULL;
    while(1){
    int valores[10] = {5, 3, 7, 2, 4, 6, 8, 1, 9, 0};
    for(int i = 0; i < 10; i++){
        Arvore = inserir(Arvore, valores[i]);
    }

    printf("Digite o numero que deseja buscar na arvore: \n");
    int num;
    scanf("%d", &num);
    if(buscar(Arvore, num)){
        printf("Numero %d encontrado na arvore.\n", num);
    } else {
        printf("Numero %d nao encontrado na arvore.\n", num);
    }

    printf("Elementos da arvore em ordem: ");
    emOrdem(Arvore);

    inserirTrie(raizTrie, "casa");
    inserirTrie(raizTrie, "casal");
    inserirTrie(raizTrie, "caminho");
    inserirTrie(raizTrie, "carro");
    inserirTrie(raizTrie, "gato");

    printf("Digite uma palavra para buscar na trie: ");
    char busca[100];
    scanf("%s", busca);
    if(buscarTrie(raizTrie, busca)){
        printf("Palavra '%s' encontrada na trie.\n", busca);
    } else {
        printf("Palavra '%s' nao encontrada na trie.\n", busca);
    }

    }


}
