#include<stdio.h>
#include<string.h>

void modificar_elementos(int *v, int tamanho){
    for(int i = 0; i< tamanho; i++){
        *(v+i) += 5;
    }
}

int main(){
    int vet[5] = {1, 2, 3, 4, 5};
    int *ptr = &vet;
    int **ptr1 = &ptr;

    
    **ptr1 = 100; // altera primeiro valor do vetor para 100
    for(int i=0; i<5; i++){  // imprime vetor alterado
    printf("%d ", *(*ptr1+i));
    }
    printf("\n");
    // usando a funcao modificar_elementos
    modificar_elementos(vet,5);
    for(int i=0; i<5; i++){  // imprime vetor alterado
    printf("%d ", vet[i]);
    }


}