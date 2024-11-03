void soma(void *a, void *b, char tipo) {
    if (tipo == 'i') {
        int resultado = *(int *)a + *(int *)b;
        printf("Resultado: %d\n", resultado);
    } else if (tipo == 'f') {
        float resultado = *(float *)a + *(float *)b;
        printf("Resultado: %.2f\n", resultado);
    } else if (tipo == 'd') {
        double resultado = *(double *)a + *(double *)b;
        printf("Resultado: %.3lf\n", resultado);
    } else {
        printf("Tipo inválido!\n");
    }
}
