#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>

sem_t chopstick[5];
int i;

void* philosopher(void* f)
{
	int cur = *(int*)f;
	do
	{
		sem_wait(&chopstick[cur]);
		sem_wait(&chopstick[(cur+1)%5]);
		printf("%d %s\n",cur,"th philosopher is eating");
		sem_post(&chopstick[cur]);
		sem_post(&chopstick[(cur+1)%5]);
		printf("%d %s\n",cur,"th philosopher has finished eating");
		sleep(1);
	}while(1);
}

int main()
{
	pthread_t tid[5];
	int arr[]={0,1,2,3,4,5};
	for(i=0; i<5; i++)
	sem_init(&chopstick[i],0,1);
	for(i=0; i<5; i++)
	pthread_create(&tid[i], NULL, philosopher, &arr[i]);
	for(i=0; i<5; i++)
	pthread_join(tid[i], NULL);
}
