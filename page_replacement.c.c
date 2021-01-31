#include<stdio.h>
#include<math.h>
#define MAX 100
int page[MAX],frames,string[MAX],str,hit=0,fault=0;
void fifo()
{
    initialize();
    for(int i=0;i<str;i++)
    {
        printf("\nFor %d :",string[i]);
        if(isHit(string[i])==0)
        {

            for(int j=0;j<frames-1;j++)
            {
                page[j]=page[j+1];
            }
            page[j]=string[i];
            fault++;
            dispPages();
        }
        else
            printf("\tNo page fault");
    }
    dispPgFaultCnt();
}
void lru()
{
    initialize();
    int recent[50];
    for(int i=0;i<str;i++)
    {
        printf("\nFor %d :",string[i]);

        if(isHit(string[i])==0)
        {

            for(int j=0;j<frames;j++)
            {
                int pg=page[j];
                int found=0;
                for(int k=i-1;k>=0;k--)
                {
                    if(pg==string[k])
                    {
                        recent[j]=k;
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    recent[j]=-MAX;
            }
            int min=MAX;
            int repindex;
            for(int j=0;j<frames;j++)
            {
                if(recent[j]<min)
                {
                    min=recent[j];
                    repindex=j;
                }
            }
            page[repindex]=string[i];
            fault++;
            dispPages();
        }
        else
            printf("\tNo page fault!");
    }
    dispPgFaultCnt();
}
void lfu()
{
    int us[100];
    int freq,rep,freq1=0,bn;
    initialize();
    for(int i=0;i<frames;i++)
        {
            us[i]=0;
        }
    for(int i=0;i<str;i++)
    {

        printf("\n For %d :",string[i]);
        if(isHit(string[i]))
        {
            int hitind=getHitIndex(string[i]);
            us[hitind]++;
            printf("\tNo page fault!");
        }
        else
        {
            fault++;
            if(bn<str)
            {
                p[bn]=in[i];
                us[bn]=us[bn]+1;
                bn++;
            }
            else
            {
                freq=MAX;
                for(int k=0;k<frames;k++)
                    if(us[k]<freq)
                    {
                        freq=us[k];
                        rep=k;
                    }
                page[rep]=string[i];
                freq1=0;
                for(int k=0;k<=i;k++)
                {
                    if(string[i]==string[k])
                        {
                            freq1=freq1+1;
                        }
                }
                us[rep]=freq1;
            }
            dispPages();
        }

    }
    dispPgFaultCnt();
}
void initialize()
{
    fault=0;
    for(int i=0;i<frames;i++)
        {
            page[i]=9999;
        }
}

int isHit(int data)
{
    hit=0;
    for(int i=0;i<frames;i++)
    {
        if(page[i]==data)
        {
            hit=1;
            break;
        }
    }
    return hit;
}
int getHitIndex(int data)
{
    int hitind;
    for(int i=0;i<frames;i++)
    {
        if(page[i]==data)
        {
            hitind=i;
            break;
        }
    }
    return hitind;
}

void dispPages()
{
    for (int i=0;i<frames;i++)
    {
        if(page[i]!=MAX)
            printf(" %d",page[i]);
    }

}

void dispPgFaultCnt()
{
    printf("\nTotal no of page faults:%d",pgfaultcnt);
}

void queue_insert(int v)
{
    if(isfull())
    {

    }
    else
    {
        if (front==-1)
        {
            front=0;
        }
        rear=(rear+1)%frames;
        page[rear]=v;
    }
}
void queue_delete()
{
    int element;
    if (isempty())
    {
        printf("\n Queue is empty !! \n");
    }
    else
    {
        element=page[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%frames;
        }
    }
}
int isfull()
{
    if((front==(rear+1))||((front==0)&&(rear==(frames-1))))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty()
{
    if (front==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void main()
{
    int y=1;
    while(y==1)
    {
        printf("Enter the page slot\n");
        scanf("%d",&frames);
        printf("Enter the number of strings in the reference string\n");
        scanf("%d",&str);
        printf("Enter the reference string\n");
        for(int i=0;i<str;i++)
        {
            scanf("%d",&string[i]);
        }
        int m=1;
        while(m==1)
        {
            int ch;
            printf("To do FIFO page replacement algorithm press 1\nTO do LRU page replacement algorithm press 2\nTo do LFU page replacement algorithm press 3\n");
            scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                fifo();
                break;

            case 2:
                lru();
                break;

            case 3:
                lfu();
                break;

            default:
                printf("\nWrong choice\n");
                break;
            }
            printf("To check with other algorithm press 1, else press any other number\n");
            scanf("%d",&m);
        }
        printf("To continue with the program press 1, else press any other number\n");
        scanf("%d",&y);
    }
}
