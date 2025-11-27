#include <stdio.h>
#include <pthread.h>

//without semaphore-using thread and turn variable
int a=0;
void *producer()
{
    a++;
    return NULL;
}
void *consumer()
{
    printf("A=%d\n",a);
    return NULL;
}
int main()
{
    int turn=0;
    pthread_t prod,cons;
    for(int i=0;i<100;i++)
    {
        if(turn==0)
        {
            pthread_create(&prod,NULL,producer,NULL);
            pthread_join(prod,NULL);
            turn=1;
        }
        if(turn==1)
        {
            pthread_create(&cons,NULL,consumer,NULL);
            pthread_join(cons,NULL);
            turn=0;
        }
    }
    return 0;
}
