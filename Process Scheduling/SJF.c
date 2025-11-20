#include<stdio.h>
#include<limits.h>
struct Process
{
    int pid,at,bt,ct,tat,wt,completed;
}p[5];
void sorting(struct Process p[],int n)
{
    for(int i=0;i<5;i++)
    {
        for(int j=i;j<5;j++)
        {
            if(p[i].bt>p[j].bt)
            {
                struct Process temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
}
void completion(struct Process p[], int n)
{
    int time=0,done=0;

    while(done<n)
    {
        int idx=-1;//Index of process to execute
        int minBT=INT_MAX;//Very large number initially

        //Find process with minimum BT among arrived and not completed
        for(int i=0; i<n;i++)
        {
            if(p[i].at<=time && p[i].completed==0 && p[i].bt<minBT)
            {
                minBT=p[i].bt;
                idx=i;
            }
        }

        //If no process has arrived yet, move time forward
        if(idx==-1)
        time++;

        else
        {
            time+=p[idx].bt; // Process runs completely
            p[idx].ct=time;  // Completion time
            p[idx].completed=1;
            done++;
        }
    }
}

void turnArround(struct Process p[],int n)
{
    for(int i=0;i<5;i++)
    p[i].tat=p[i].ct-p[i].at;
}
void waiting(struct Process p[],int n)
{
    for(int i=0;i<5;i++)
    p[i].wt=p[i].tat-p[i].bt;
}
int main()
{
    int n=5;
    float totalwt=0,totaltat=0;
    for(int i=0;i<5;i++)
    p[i].pid=i;

    p[0].at=4;
    p[1].at=3;
    p[2].at=1;
    p[3].at=0;
    p[4].at=2;

    p[0].bt=3;
    p[1].bt=5;
    p[2].bt=4;
    p[3].bt=2;
    p[4].bt=1;

    sorting(p,n);
    completion(p,n);
    turnArround(p,n);
    waiting(p,n);

    for(int i=0;i<5;i++)
    {
        printf("%d  %d  %d  %d  %d  %d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
        totalwt=totalwt+p[i].wt; 
        totaltat=totaltat+p[i].tat;
    }
    printf("Average turn around time: %f\n",totaltat/5); 
    printf("Average waiting time: %f\n",totalwt/5);

    printf("\nGantt chart:\n"); 
    for(int i=0;i<n;i++) 
    printf(" P%d |", p[i].pid); 

    printf("\n0"); 
    for(int i=0;i<n;i++) 
    printf("   %d", p[i].ct);
}
