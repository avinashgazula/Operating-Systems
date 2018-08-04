#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
sem_t full,empty,mutex;
int buffer[20],in=0,out=0,size=10,val=0;
void produce()
{
	while(1)
	{
		sem_wait(&empty);
		sem_wait(&mutex);
		in=(in+1)%size;
		buffer[in]=val++;
		printf("%s%d\n","producing : ",val-1);
		sleep(1);
		sem_post(&mutex);
		sem_post(&full);
	}
}
void consume()
{
	while(1)
	{
		sem_wait(&full);
		sem_wait(&mutex);
		out=(out+1)%size;
		printf("%s%d\n","consuming : ",buffer[out]);
		sleep(1);
		sem_post(&mutex);
		sem_post(&empty);
	}
}
int main()
{
	sem_init(&full,0,0);
	sem_init(&empty,0,10);
	sem_init(&mutex,0,1);
	pthread_t t1,t2;
	pthread_create(&t1,NULL,produce,NULL);
	pthread_create(&t2,NULL,consume,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return 0;
}
