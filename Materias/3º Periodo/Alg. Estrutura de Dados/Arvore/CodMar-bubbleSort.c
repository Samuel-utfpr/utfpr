#include<stdbool.h>
#include<stdlib.h>

void printArray(int *array, int N){
	int i;
	printf("Vetor = [ ");
	for(i=0;i<N;i++){
		printf("%d ", array[i]);
	}
	printf(" ] ");
}

void bubbleSort(int *array, int N){
	int i, aux;
	bool trocou = true;
	while(trocou){
		trocou = false;
		for(i=0;i<(N-1);i++){
			if(array[i]>array[i+1]){
				aux = array[i];
				array[i] = array[i+1];
				array[i+1] = aux;
				trocou = true;
			}
		}
	}
}
int main(){
	int vetor[]={5,3,6,9,8,4,1,12,85,7};
	printArray(vetor, 10);
	printf("\nAgora o vetor ordenado\n");
	bubbleSort(vetor, 10);
	printArray(vetor, 10);
	return 0;
}