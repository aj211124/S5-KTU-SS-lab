#include<stdio.h>
#include<stdlib.h>
void main()
{
    int w=1;
    while(w==1)
    {
    int p,r,w1=0,w2=0,w3=0;
    printf("Enter the number of process ");
    scanf("%d",&p);
    printf("Enter the number of resource ");
    scanf("%d",&r);
    int allo[p][r],max[p][r],need[p][r],ava[r];
    while(w1!=1)
    {
        printf("Enter the allocation matrix:\n");
        for(int i=0;i<p;i++)
        {
            for(int j=0;j<r;j++)
            {
                scanf("%d",&allo[i][j]);
            }
        }
        printf("You have entered allocation matrix as\n");
        for(int i=0;i<p;i++)
        {
            for(int j=0;j<r;j++)
            {
                printf("%d\t",allo[i][j]);
            }
            printf("\n");
        }
        printf("To confirm enter 1,else enter any other number ");
        scanf("%d",&w1);
    }
    while(w2!=1)
    {
        printf("Enter the max matrix:\n");
        for(int i=0;i<p;i++)
        {
            for(int j=0;j<r;j++)
            {
                scanf("%d",&max[i][j]);
            }
        }
        printf("You have entered max matrix as\n");
        for(int i=0;i<p;i++)
        {
            for(int j=0;j<r;j++)
            {
                printf("%d\t",max[i][j]);
            }
            printf("\n");
        }
        printf("To confirm enter 1,else enter any other number ");
        scanf("%d",&w2);
    }
    while(w3!=1)
    {
        printf("Enter the available resources\n");
        for(int i=0;i<r;i++)
        {
            scanf("%d",&ava[i]);
        }
        printf("You have entered available resources as\n");
        for(int i=0;i<r;i++)
        {
                printf("%d\t",ava[i]);
        }
        printf("\nTo confirm enter 1,else enter any other number ");
        scanf("%d",&w3);
    }
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            need[i][j]=max[i][j]-allo[i][j];
        }
    }
    printf("The remaining resource need for each resource is\n");
     for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }
    int y,work[10],z=0,finish[10];
    for(int i=0;i<r;i++)
    {
        finish[i]=0;
    }
    for(int i=0;i<p;i++)
    {
        work[i]=i;
    }
    for(int k=0;k<p;k++)
    {
        for(int i=0;i<p;i++)
         {
            if(finish[i]==0)
            {
                int flag=0;
                for(int j=0;j<r;j++)
                {
                    if (need[i][j]>ava[j])
                    {
                        flag=1;
                         break;
                    }
                }

                if(flag==0)
                {
                    work[z++]=i;
                    for(y=0;y<r;y++)
                    {
                        ava[y]+=allo[i][y];
                    }
                    finish[i]=1;
                }
            }
        }
    }
    int e=0;
    for(int i=0;i<p;i++)
    {
        if(finish[i]==0)
        {
            e=1;
            break;
        }
    }
    int m=1;
    while(m==1)
    {
    printf("To check safety algorithm enter 1\nTo check resource-request enter 2\n");
    int ch;
    scanf("%d",&ch);
    if(ch==1)
    {
        if(e==0)
        {
            printf("The system is in safe state\n");
        }
        else
        {
            printf("The system is in unsafe state\n");
        }
    }
    else if(ch==2)
    {
    if(e==0)
    {
    printf("Following is the safe Sequence\n");
    for(int i=0;i<p-1;i++)
    {
        printf("P%d->",work[i]);
    }
    printf(" P%d",work[p-1]);
    }
    }
    else
    {
        printf("Invalid statement");
    }
    printf("\nTo continue with the current process enter 1\nElse enter any other number\n");
    scanf("%d",&m);
    }
    printf("\nTo try with new process enter 1\nTo end the program enter any other number\n");
    scanf("%d",&w);
    }
}
