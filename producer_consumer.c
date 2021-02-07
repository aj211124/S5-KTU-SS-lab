#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define MAXSIZE 10
sem_t full,empty,mutex;
pthread_t ptd[2];
int buffer[10];
int in,out;
int *producer(int *);
int *consumer(int *);

int main(void)
{
   int ret_thread1,ret_thread2,i;
 int id[2]={0,1};
        sem_init(&full,0,0);
 sem_init(&empty,0,MAXSIZE);
 sem_init(&mutex,0,1);

 
  ret_thread1=pthread_create(&ptd[0],NULL,(void *)producer,&id[0]);
 if(ret_thread1<0)
               printf("Thread creation Failed");
         //sleep(1);
 ret_thread2=pthread_create(&ptd[1],NULL,(void *)consumer,&id[1]);
 if(ret_thread2<0)
               printf("Thread creation Failed");
  
    pthread_join(ptd[0],NULL);
 pthread_join(ptd[1],NULL);
 
 
}

int *producer(int *id)
{
int i,value,item;

in=0;
while(1)
{
sleep(1);
sem_getvalue(&full,&value);// getting the current value of semaphore
if(value==MAXSIZE-1)
{
printf("OVERFLOW");
break;
}

sem_wait(&mutex);
sem_wait(&empty);//wait
item=rand()%100;
//prod->in=item;
buffer[in]=item;
printf("The index is %d",in);
printf("\nThe item produced is %d ",buffer[in]);
in=(in+1)%(MAXSIZE);

sem_post(&full);
sem_post(&mutex);//signal

//printf("\nThe current value of semaphore is %d",value);

}
return 0;
}



int *consumer(int *id)
{
int value,item;
in=0;
while(1)
{
sleep(2);
sem_getvalue(&empty,&value);// getting the current value of semaphore
if(value==-1)
{
printf("UNDERFLOW");
break;
}

sem_wait(&mutex);
sem_wait(&full);//wait
//item=rand()%100;
//prod->in=item;
in=(in-1)%(MAXSIZE);
item=buffer[in];
printf("The index is %d",in);
printf("\nThe item consumed is %d ",item);


sem_post(&empty);
sem_post(&mutex);//signal

//printf("\nThe current value of semaphore is %d",value);

}

return 0;
}
