#include <stdio.h>

void printMatriz (int l, int c, int matriz[3][3]){
   int i1 = 0, i2 = 0;
    for (i1=0; i1<l; i1++){
        for (i2=0; i2<c; i2++){
            printf("%d ", matriz[i1][i2]);
        }
        printf(" \n");
    }

}
int processaMatriz (int l, int c, int x, int matriz[3][3]){
    int alteracao = 0, i1 = 0, i2 = 0;
    for (i1=0; i1<l; i1++){
        for (i2=0; i2<c; i2++){
            if(matriz[i1][i2] > x){
            matriz[i1][i2] = 0;
            alteracao ++;
            }

        }
    }

    return alteracao;
}

int main(){
    int x, alteracoes=0;
	int matriz[3][3];
	scanf("%d",&x);
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
	alteracoes = processaMatriz(3, 3, x, matriz);
	printMatriz(3, 3, matriz);
	printf("Alteracoes=%d",alteracoes);
}