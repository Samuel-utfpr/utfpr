int** aloca_matriz(int m, int n){
    int **ma = (int **)malloc(m*sizeof(int *));
    int i;
    for(i=0;i<m;i++){
        ma[i] = (int *)malloc(n*sizeof(int));
            
    }
    return ma;
}