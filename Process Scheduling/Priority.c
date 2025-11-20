#include<stdio.h>
struct Process
{
    int pid,at,bt,ct,tat,wt,pr,completed;
}p[5];
void sorting(struct Process p[],int n)
{
    for(int i=0;i<5;i++)
    {
        for(int j=i;j<5;j++)
        {
            if(p[i].at>p[j].at)
            {
                struct Process temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
}
void completion(struct Process p[],int n)
{
    int time=0,done=0;

    while(done<n)
    {
        int idx=-1;
        int highPriority=9999;//lower number=higher priority

        for(int i=0;i<n;i++)
        {
            if(p[i].at<=time && p[i].completed==0 && p[i].pr<highPriority)
            {
                highPriority=p[i].pr;
                idx=i;
            }
        }

        //If no process has arrived yet
        if(idx == -1)
        time++;

        else
        {
            time+=p[idx].bt;
            p[idx].ct=time;
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
    float totaltat=0,totalwt=0;
    for(int i=0;i<5;i++)
    p[i].pid=i;

    p[0].at=4;
    p[1].at=3;
    p[2].at=1;
    p[3].at=0;
    p[4].at=2;

    p[0].bt=5;
    p[1].bt=4;
    p[2].bt=2;
    p[3].bt=1;
    p[4].bt=3;

    // Priorities(lower number=higher priority)
    p[0].pr=3; 
    p[1].pr=1; 
    p[2].pr=4; 
    p[3].pr=2; 
    p[4].pr=5;
    sorting(p,n);
    completion(p,n);
    turnArround(p,n);
    waiting(p,n);

    printf("PId  AT  Priority  BT  CT  TAT  WT\n");
    for(int i=0;i<5;i++)
    {
        printf("%d    %d   %d         %d    %d   %d  %d\n",p[i].pid,p[i].at,p[i].pr,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
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
