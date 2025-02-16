#include<stdio.h>

int* aloca_vetor(int n){
    int *v = (int*)malloc(n*sizeof(int));
    return v;
}
void le_elementos(int* v,int n){
    int i;
    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
}
void print_vetor(int*v, int n){
    int i, soma = 0;
    for (i=0;i<n;i++){
        printf("v[%d]=%d \n", i, v[i]);
        soma = soma + v[i];
    }
    float media = (float)soma / n;
    printf("Media=%.2lf", media);

}
