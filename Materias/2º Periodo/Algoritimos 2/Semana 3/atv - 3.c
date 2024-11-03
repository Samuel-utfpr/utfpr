
void inverter(int tamanho, int vetor[tamanho]){
    int vetor2[tamanho];
    
    for(int i=0; i<tamanho; i++){
        vetor2[(tamanho-1)-i] = vetor[i];
    }

    for(int i=0; i<tamanho; i++){
        vetor[i] = vetor2[i];
    }
}

void printVetor(int tamanho, int vetor[tamanho]){
    for(int i=0; i<tamanho; i++){
        printf("%d ", vetor[i]);
    }
}


int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];
        
    for (int i=0; i<n; i++){
        scanf("%d", &vetor[i]);
    }
    inverter(n, vetor);
    printVetor(n, vetor);
}