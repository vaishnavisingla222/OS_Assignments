#include<stdio.h>
struct Process
{
    int pid,completed;
    int allocated[3],need[3],max[3];//allocated->number of instace of a resource by each process, need->more number of intace of resource required by that process, max->total number of intance required by that process to work
}p[5];
int main()
{
    int available[3],check=1,count=0;
    printf("Enter the max and allocated number of intance of each resource(allocated<max):\n");
    for(int i=0;i<5;i++)
    {
        p[i].pid=i;
        for(int j=0;j<3;j++)
        {
            scanf("%d,%d",&p[i].max[j],&p[i].allocated[j]);
            p[i].need[j]=p[i].max[j]-p[i].allocated[j];
        }
        p[i].completed=0;
    }
    printf("Enter the number of intance available for each resource: ");
    for(int i=0;i<3;i++)
    scanf("%d",&available[i]);

    while(count<5)
    {
        int executed=0;
        for(int i=0;i<5;i++)
        {
            if(p[i].completed==1)
            continue;

            int possible=1;
            for(int j=0;j<3;j++)
            {
                if(p[i].need[j]<=available[j])
                possible=1;

                else
                {
                    possible=0;
                    break;
                }
            }
            if(possible)
            {
                executed=1;//if for 1 time also any process worked then it need to check once again
                count++;
                p[i].completed=1;
                printf("Process %d executed\n",i);

                for(int j=0;j<3;j++)
                available[j]+=p[i].allocated[j];
            }
        }
        if(executed==0)
        {
            check=0;
            break;
        }
    }
    if(check==0)
    printf("\nCannot be completely executed\n");

    else
    printf("\nProcess executed safely\n");
    return 0;
}
