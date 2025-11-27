#include<stdio.h>
void firstFit(int pro,int proSize[],int hole,int holeSize[],int allocated[])
{
    for(int i=0;i<pro;i++)
    {
        if (allocated[i]==1)
        continue;

        for(int j=0;j<hole;j++)
        {
            if(holeSize[j]>=proSize[i])
            {
                printf("%d is alloacated to %d\n",proSize[i],holeSize[j]);
                allocated[i]=1;
                holeSize[j]=holeSize[j]-proSize[i];
                break;
            }
        }
        if(allocated[i]==0)
        printf("%d is not alloted\n",proSize[i]);
    }
    return;
}
void bestFit(int pro,int proSize[],int hole,int holeSize[],int allocated[])
{
    for(int i=0;i<pro;i++)
    {
        int min=-1;
        int ind=-1;
        if (allocated[i]==1)
        continue;

        for(int j=0;j<hole;j++)
        {
            if(holeSize[j]>=proSize[i])
            {
                if(min==-1 || min>holeSize[j])
                {
                    min=holeSize[j];
                    ind=j;
                }
                allocated[i]=1;
            }
        }
        if(allocated[i]==0)
        printf("%d is not alloted\n",proSize[i]);
        else
        {
            printf("%d is alloacated to %d\n",proSize[i],min);
            holeSize[ind]=holeSize[ind]-proSize[i];
        }
    }
}
void worstFit(int pro,int proSize[],int hole,int holeSize[],int allocated[])
{
    for(int i=0;i<pro;i++)
    {
        int max=-1;
        int ind=-1;
        if (allocated[i]==1)
        continue;

        for(int j=0;j<hole;j++)
        {
            if(holeSize[j]>=proSize[i])
            {
                if(max==-1 || max<holeSize[j])
                {
                    max=holeSize[j];
                    ind=j;
                }
                allocated[i]=1;
            }
        }
        if(allocated[i]==0)
        printf("%d is not alloted\n",proSize[i]);
        else
        {
            printf("%d is allocated to %d\n",proSize[i],max);
            holeSize[ind]=holeSize[ind]-proSize[i];
        }
    }
}
int main()
{
    int pro,hole;
    printf("Enter the number of processes: ");
    scanf("%d",&pro);
    int proSize[pro];

    printf("Enter the number of holes: ");
    scanf("%d",&hole);
    int holeSize[hole];
    
    printf("Enter the size of processes: ");
    for(int i=0;i<pro;i++)
    scanf("%d",&proSize[i]);

    printf("Enter the size of hole: ");
    for(int i=0;i<hole;i++)
    scanf("%d",&holeSize[i]);

    int allocated[pro];
    for(int i=0;i<pro;i++)
    allocated[i]=0;

    int choice;
    printf("By which you want to fit the processes?\n1 for first fit\n2 for best fit\n3 for worst fit\n:");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        firstFit(pro,proSize,hole,holeSize,allocated);
        break;

        case 2:
        bestFit(pro,proSize,hole,holeSize,allocated);
        break;

        case 3:
        worstFit(pro,proSize,hole,holeSize,allocated);
        break;

        default:
        printf("Exiting...\n");
    }
    return 0;
}
