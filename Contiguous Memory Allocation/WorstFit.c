#include<stdio.h>
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

    int alloacated[pro];
    for(int i=0;i<pro;i++)
    alloacated[i]=0;

    for(int i=0;i<pro;i++)
    {
        int max=-1;
        int ind=-1;
        if (alloacated[i]==1)
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
                alloacated[i]=1;
            }
        }
        if(alloacated[i]==0)
        printf("%d is not alloted\n",proSize[i]);
        else
        {
            printf("%d is alloacated to %d\n",proSize[i],max);
            holeSize[ind]=holeSize[ind]-proSize[i];
        }
    }
}
