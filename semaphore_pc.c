#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
#include<unistd.h>

int buffer[50];
sem_t slock;
int p = 0, c = 0;

void *producer(void *f){
	srand(time(NULL));
	while(1){
		if((p+1)%50==c) sleep(1);
		sem_wait(&slock);
		buffer[p] = 1+rand()%50;
		printf("%s %d %d\n", "producer", p, buffer[p]);
		p = (p+1)%50;
		sem_post(&slock);
		sleep(1);
	}
}

void *consumer(void *f){
	while(1){
		if(p==c && buffer[(p+1)%50]==0) sleep(1);
		sem_wait(&slock);
		printf("%s %d %d\n", "consumer", c, buffer[c]);
		if(buffer[c]!=0)
		c = (c+1)%50;
		sem_post(&slock);
		sleep(1);
	}
}

int main(int argc, char* argv[]){
	pthread_t t1,t2;
	sem_init(&slock,0,1);
    
    pthread_create(&t1,NULL,producer,NULL);
    pthread_create(&t2,NULL,consumer,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
}
