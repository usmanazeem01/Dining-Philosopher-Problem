#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
using namespace std;
sem_t chopstick[5];
void * philosopher(void * n)
 {
         int ph=*(int *)n;
         //printf("Philosopher %d wants to eat\n",ph);
         cout<<"\nPhilospher "<<ph <<" wants to eat\n";
        cout<<"\nPhilosopher "<<ph<<" tries to pick left chopstick\n";
         sem_wait(&chopstick[ph]);
         cout<<"\nPhilospher "<<ph<<" picks the left chopstick\n";
		cout<<"\nPhilosopher "<<ph<<" tries to pick right chopstick\n";
         sem_wait(&chopstick[(ph+1)%5]);
         cout<<"Philospher "<<ph<<" picks the right chopstick\n";
      cout <<"Philosopher " <<ph <<" begins to eat\n";
         sleep(1);
        cout <<"\nPhilosopher "<<ph<<" has finished eating\n";
         sem_post(&chopstick[(ph+1)%5]);
        cout<<"\nPhilosopher "<<ph <<" leaves the right chopstick\n";
         sem_post(&chopstick[ph]);
	cout<< "\n Philosopher "<<ph<<" leaves the left chopstick\n";
 }
int main()
 {
         int i,n[5];
         pthread_t th[5];
         for(i=0;i<5;i++)
         sem_init(&chopstick[i],0,1);
         for(i=0;i<5;i++){
                 n[i]=i;
                 pthread_create(&th[i],NULL,philosopher,(void *)&n[i]);
                 }
         for(i=0;i<5;i++)
                 pthread_join(th[i],NULL);
                 
                 return 0;
 }