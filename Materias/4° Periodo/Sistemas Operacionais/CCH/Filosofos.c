#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5 
sem_t garfos[N];

int esquerda(int p) {
    return p;
}
int direita(int p) {
    return (p + 1) % N;
}


void pegaGarfos(int p){
    if (p == N - 1) {
        sem_wait(&garfos[direita (p)]);
        printf("Filósofo %d pegou o garfo direito\n", p);
        sem_wait(&garfos[esquerda (p)]);
        printf("Filósofo %d pegou o garfo esquerdo\n", p);
    } else {
        sem_wait(&garfos[esquerda (p)]);
        printf("Filósofo %d pegou o garfo esquerdo\n", p);
        sem_wait(&garfos[direita (p)]);
        printf("Filósofo %d pegou o garfo direito\n", p);
    }
}

void devolveGarfos(int p){
    sem_post(&garfos[esquerda (p)]);
    printf("Filósofo %d devolveu o garfo esquerdo\n", p);
    sem_post(&garfos[direita (p)]);
    printf("Filósofo %d devolveu o garfo direito\n", p);
}

void pensa(int p){
    printf("Filósofo %d está pensando\n", p);
}

void come(int p){
    printf("Filósofo %d está comendo\n", p);
}

void acabou(int p){
    printf("Filósofo %d terminou de comer\n", p);
}

void* filosofo(void* num) {
    int i = 0;
    int p = *(int*)num;
    for (i = 0; i < 5; i++) {
        pensa(p);
        pegaGarfos(p);
        come(p);
        devolveGarfos(p);
        acabou(p);

    }
}

int main() {
    pthread_t threads[N];
    int ids[N];
    for (int i = 0; i < N; i++) {
        sem_init(&garfos[i], 0, 1);
    }
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, filosofo, &ids[i]);
    }
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }
    for (int i = 0; i < N; i++) {
        sem_destroy(&garfos[i]);
    }
}