#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int shared=0;
sem_t mutex;

void* thread_func(void* arg) 
{
    for (int i=0; i<5;i++) 
    {
        sem_wait(&mutex);//Enter critical section

        int temp=shared;
        temp++;
        printf("Thread %ld updated value to %d\n",pthread_self(),temp);
        shared=temp;

        sem_post(&mutex);//Exit critical section
        sleep(1);
    }
    return NULL;
}
int main() 
{
    pthread_t t1, t2;
    sem_init(&mutex,0,1);

    pthread_create(&t1,NULL,thread_func,NULL);
    pthread_create(&t2, NULL,thread_func,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("Final value of shared variable = %d\n",shared);
    sem_destroy(&mutex);
    return 0;
}
