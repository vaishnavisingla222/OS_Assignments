#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define bufferSize 5

int buffer[bufferSize];
int in=0,out=0;
sem_t empty,full,mutex;

void* producer(void* arg) 
{
    int item=1;
    while (1) 
    {
        sem_wait(&empty);
        sem_wait(&mutex);// enter critical section

        buffer[in]=item;
        printf("Producer produced: %d\n",item);
        in=(in+1)%bufferSize;
        item++;

        sem_post(&mutex);//leave critical section
        sem_post(&full);
        sleep(1);
    }
}

void* consumer(void* arg) 
{
    while(true) 
    {
        sem_wait(&full);
        sem_wait(&mutex);//enter critical section

        int item=buffer[out];
        printf("Consumer consumed: %d\n",item);
        out = (out+1)%bufferSize;

        sem_post(&mutex);//leave critical section
        sem_post(&empty);
        sleep(2);
    }
}

int main() 
{
    pthread_t prod,cons;

    sem_init(&empty,0,bufferSize);
    sem_init(&full,0,0);
    sem_init(&mutex,0,1);

    pthread_create(&prod,NULL,producer,NULL);
    pthread_create(&cons,NULL,consumer,NULL);

    pthread_join(prod,NULL);
    pthread_join(cons,NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}
