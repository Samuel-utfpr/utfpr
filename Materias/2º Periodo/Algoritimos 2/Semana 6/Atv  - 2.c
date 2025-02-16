int** aloca_matriz_quadrada(int n){
    int **m = (int **)malloc(n*sizeof(int *));
    int i;
    for(i=0;i<n;i++){
        m[i] = (int *)malloc(n * sizeof(int));

    }
    return m;
}