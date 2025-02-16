int** matriz_irregular(int n, int* v){
    int **m = (int **)malloc(n*sizeof(int *));
    int i, j;
    for(i=0;i<n;i++){
        m[i] = (int *)malloc(v[i] * sizeof(int));
            for(j=0; j<v[i];j++){
                m[i][j] = v[i];
            }
    }
    return m;
}