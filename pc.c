#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>


#define MAX_BUFFER_SIZE 5


int buffer[MAX_BUFFER_SIZE];
int in = 0;
int out = 0;


sem_t empty;
sem_t full;
sem_t mutex;

void producer() {
    int item;
    while (1) {
        item = rand() % 100; 
        printf("Produced: %d\n", item);

        sem_wait(&empty);   
        sem_wait(&mutex);   

        buffer[in] = item;   
        in = (in + 1) % MAX_BUFFER_SIZE;

        sem_post(&mutex);    
        sem_post(&full);  
        sleep(1); 
    }
}

void consumer() {
    int item;
    while (1) {
        sem_wait(&full);    
        sem_wait(&mutex);   

        item = buffer[out];  
        out = (out + 1) % MAX_BUFFER_SIZE;
        printf("Consumed: %d\n", item);

        sem_post(&mutex);    
        sem_post(&empty);    

        sleep(1); 
    }
}

int main() {
    pthread_t prod_thread, cons_thread;

    
    sem_init(&empty, 0, MAX_BUFFER_SIZE); 
    sem_init(&full, 0, 0);                
    sem_init(&mutex, 0, 1);              

    
    pthread_create(&prod_thread, NULL, (void*)producer, NULL);
    pthread_create(&cons_thread, NULL, (void*)consumer, NULL);


    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}

