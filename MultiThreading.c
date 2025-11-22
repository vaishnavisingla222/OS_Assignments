#include <stdio.h>
#include <pthread.h>

int data[10];
int sum=0;
int max=0;

void* calcSum(void* arg)
{
    for(int i=0;i<10;i++)
    sum=sum+data[i];

    pthread_exit(NULL);
}
void* findMax(void* arg)
{
    max=data[0];
    for(int i=0;i<10;i++)
    {
        if(data[i]>max)
        max=data[i];
    }

    pthread_exit(NULL);
}
int main()
{
    printf("Enter the ellements of array: ");
    for(int i=0;i<10;i++)
    scanf("%d",&data[i]);

    pthread_t t1,t2;
    pthread_create(&t1,NULL,calcSum,NULL);
    pthread_create(&t2,NULL,findMax,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("Sum of array: %d\n",sum);
    printf("Maximum value in array: %d\n",max);
    return 0;
}
