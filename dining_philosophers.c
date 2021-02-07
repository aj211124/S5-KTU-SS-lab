#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#define LEFT  phil_num
#define RIGHT (phil_num+1)%5
sem_t chopstick[5],mutex;
int phil_number[5]={0,1,2,3,4};
pthread_t ptd[5];

void *philosopher(int *);

void main()
{
   int ret_thread,i;
 for(i=0;i<5;i++)
        sem_init(&chopstick[i],0,1);
 for(i=0;i<5;i++)
 {
  ret_thread=pthread_create(&ptd[i],NULL,(void *)philosopher,&phil_number[i]);
 if(ret_thread<0)
               printf("Thread creation Failed");
 }
  for(i=0;i<5;i++)
    pthread_join(ptd[i],NULL);
 
}

void *philosopher(int *phil_num)
{
int i;
//while(1)
i=*phil_num;
printf("\nPhilosopher %d is thinking",i+1);
//printf("Philosopher ID is %d",i);
sleep(2);
sem_wait(&chopstick[i]);
sem_wait(&chopstick[(i+1)%5]);
printf("\nPhilosopher %d is eating",i+1);
sleep(2);
sem_post(&chopstick[i]);
sem_post(&chopstick[(i+1)%5]);
printf("\nPhilosopher %d is finished eating",i+1);
}
