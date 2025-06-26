#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct NoArvore* PtrNoArvore;
// NoArvore
typedef struct NoArvore {
  int chave; // valor armazenado
//  char* chave;
  PtrNoArvore direita;
  PtrNoArvore esquerda;
} NoArvore;

int contaNosArvore(PtrNoArvore *no){
    if((no) == NULL) return 0;
    return 1 + contaNosArvore(&(*no)->esquerda) + contaNosArvore(&(*no)->direita);  

}

int contaFolhasArvore(PtrNoArvore *no){
    if((no) == NULL) return 0;
    if((*no)->esquerda == NULL && (*no)->direita == NULL) return 1;
    return contaFolhasArvore(&(*no)->esquerda) + contaFolhasArvore(&(*no)->direita);
}

void mostra_chaves_decrescentes(PtrNoArvore *no) {
    if (no == NULL || *no == NULL) return;
    mostra_chaves_decrescentes(&(*no)->direita);
    printf("%d ", (*no)->chave);
    mostra_chaves_decrescentes(&(*no)->esquerda);
}