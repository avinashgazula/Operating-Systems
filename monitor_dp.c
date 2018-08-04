#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>


enum {THINKING, HUNGRY, EATING} state[5];
sem_t self[5];
sem_t mutex;

void test(int i) {
	if ((state[(i + 4) % 5] !=EATING) && (state[i] ==HUNGRY) && (state[(i + 1) % 5] !=EATING)) 
	{
		state[i] =EATING;
		printf("%d %s %d %s %d\n",i,"philosopher picks up forks",i,"and",(i+4)%5);
		printf("%d %s\n",i,"philosopher is eating");
		sem_post(&self[i]);
	}
}
void pickup(int i) 
{
	sem_wait(&mutex);
	state[i] =HUNGRY;
	printf("%d %s\n",i,"philosopher is hungry");
	test(i);
	if (state[i] != EATING)
	sem_wait(&self[i]);
	sem_post(&mutex);
}
void putdown(int i) 
{
	sem_wait(&mutex);
	state[i] =THINKING;
	printf("%d %s %d %s %d\n",i,"philosopher put down forks",i,"and",(i+4)%5);
	test((i + 4) % 5);
	test((i + 1) % 5);
	sem_post(&mutex);
}


void* philosopher(void* f)
{
        while(1)
        {
                int i=*(int *)f;
                sleep(1);
                pickup(i);
                sleep(0);
                putdown(i);
        }
}

int main()
{
	int j;
	for (j=0; j<5; j++)
	state[j] =THINKING;
	for(j=0; j<5; j++)
	sem_init(&self[j],0,1);
	sem_init(&mutex,0,1);
	pthread_t tid[5];
	int arr[5] = {0,1,2,3,4};
	for(j=0; j<5; j++)
	pthread_create(&tid[j], NULL, philosopher, &arr[j]);
	for(j=0; j<5; j++)
	pthread_join(tid[j], NULL);
}
