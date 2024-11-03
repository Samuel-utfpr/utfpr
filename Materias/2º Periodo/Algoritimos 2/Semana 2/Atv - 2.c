#include <stdio.h>
#include <limits.h>

int main() {
    int N, M;
    int i, j;
    scanf("%d %d", &N, &M);
    int matriz[N][M];

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int menor = INT_MAX;
    int linha_menor = -1;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
                linha_menor = i;
            }
        }
    }

    int minmax = INT_MIN;
    for (j = 0; j < M; j++) {
        if (matriz[linha_menor][j] > minmax) {
            minmax = matriz[linha_menor][j];
        }
    }

    printf("MinMax = %d\n", minmax);

    return 0;
}

