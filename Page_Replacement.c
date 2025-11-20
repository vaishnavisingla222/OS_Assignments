#include<stdio.h>
int fifo(int frames,int str[],int reference)
{
    int arr[frames];
    for(int i=0;i<frames;i++)
    arr[i]=-1;

    int pgFaults=0;
    int pointer=0;
    for(int i=0;i<reference;i++)
    {
        int present=0;
        for(int j=0;j<frames;j++)
        {
            if(str[i]==arr[j])
            {
                present=1;
                break;
            }
        }
        if(present==0)
        {
            pgFaults++;
            arr[pointer]=str[i];
            pointer=(pointer+1)%frames;
            // for(int j=0;j<frames;j++)
            // printf("%d ",arr[j]);
            // printf("\n");
        }
    }
    return pgFaults;
}
int lru(int frames,int str[],int reference)
{
    int arr[frames];
    int recent[frames];//to store the last used time for each frame
    for(int i=0;i<frames;i++)
    {
        arr[i]=-1;
        recent[i]=0;
    }
    int pgFaults=0;
    int time=0;
    for(int i=0;i<reference;i++)
    {
        time++;
        int present=0;
        for(int j=0;j<frames;j++)
        {
            if(str[i]==arr[j])
            {
                present=1;
                recent[j]=time;
                break;
            }
        }
        if(present==0)
        {
            pgFaults++;

            int empty=-1;//to check empty slot
            for(int j=0;j<frames;j++)
            {
                if(arr[j]==-1)
                {
                    empty=j;
                    break;
                }
            }
            if(empty!=-1)
            {
                arr[empty]=str[i];
                recent[empty]=time;
            }
            else
            {
                int ind=0;
                int min=recent[0];
                for(int j=1;j<frames;j++)
                {
                    if(recent[j]<min)
                    {
                        min=recent[j];
                        ind=j;
                    }
                }
                arr[ind]=str[i];
                recent[ind]=time;
            }
            // for(int j=0;j<frames;j++)
            // printf("%d ",arr[j]);
            // printf("\n");
        }
    }
    return pgFaults;
}
int optimised(int frames,int str[],int reference)
{
    int arr[frames];
    for(int i=0;i<frames;i++)
    arr[i]=-1;

    int pgFaults=0;
    for(int i=0;i<reference;i++)
    {
        int present=0;
        for(int j=0;j<frames;j++)
        {
            if(str[i]==arr[j])
            {
                present=1;
                break;
            }
        }
        if(present==0)
        {
            pgFaults++;
            int empty=-1;
            for(int j=0;j<frames;j++)
            {
                if(arr[j]==-1)
                {
                    empty=j;
                    break;
                }
            }
            if(empty!=-1)
            arr[empty]=str[i];

            else
            {
                int ind=-1;
                int dist=-1;
                for(int j=0;j<frames;j++)
                {
                    int next=-1;
                    for(int k=i+1;k<reference;k++)
                    {
                        if(arr[j]==str[k])
                        {
                            next=k;
                            break;
                        }
                    }
                    if(next==-1)
                    {
                        ind=j;
                        dist=reference+1;
                        break;
                    }
                    else
                    {
                        if(next>dist)
                        {
                            dist=next;
                            ind=j;
                        }
                    }
                }
                arr[ind]=str[i];
            }
            // for (int j=0;j<frames;j++)
            // printf("%d ", arr[j]);
            // printf("\n");
        }
    }
    return pgFaults;
}
int main()
{
    int noOfFrames,noOfReference;
    printf("Enter number of frames: ");
    scanf("%d",&noOfFrames);
    printf("Enter number of reference string: ");
    scanf("%d",&noOfReference);

    int str[noOfReference];
    printf("Enter the reference string: ");
    for(int i=0;i<noOfReference;i++)
    scanf("%d",&str[i]);

    int faultsFIFO=fifo(noOfFrames,str,noOfReference);
    printf("Number of page faults in FIFO algorithm: %d\n",faultsFIFO);
    
    int faultsLRU=lru(noOfFrames,str,noOfReference);
    printf("Number of page faults in LRU algorithm: %d\n",faultsLRU);

    int faultsOpt=optimised(noOfFrames,str,noOfReference);
    printf("Number of page faults in Optimised algorithm: %d\n",faultsOpt);
}
