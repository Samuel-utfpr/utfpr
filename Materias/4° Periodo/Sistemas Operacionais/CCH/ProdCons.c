#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty, full;
pthread_mutex_t mutex;

int ProcessoProdutor(){
    int dado = rand() % 100;
    return dado;
}
void ProcessoConsumidor(int dado){
    printf("Consumido: %d\n", dado);
}

void *produtor(void *arg){
    int i;
    for (i = 0; i < 10; i++)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        int dado = ProcessoProdutor();
        buffer[in] = dado;
        in = (in + 1) % BUFFER_SIZE;
        printf("Produzido: %d\n", dado);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void *consumidor(void *arg){
    int i;
    for (i = 0; i < 10; i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int dado = buffer[out];
        ProcessoConsumidor(dado);
        out = (out + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main(){
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_t prod, cons;
    pthread_create(&prod, NULL, produtor, NULL);
    pthread_create(&cons, NULL, consumidor, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
}