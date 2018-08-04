#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int buffer[50];
pthread_mutex_t lock;
int p = 0, c = 0;

void *producer(void *f){
	srand(time(NULL));
	while(1){
		while((p+1)%50==c) sleep(1); //buffer full
		pthread_mutex_lock(&lock);
		buffer[p] = rand()%50;
		printf("%s %d %d\n", "producer", p, buffer[p]);
		p = (p+1)%50;
		pthread_mutex_unlock(&lock);
		sleep(1);
	}
}

void *consumer(void *f){
	while(1){
		while(c==p) sleep(2);//buffer full
		pthread_mutex_lock(&lock);
		printf("%s %d %d\n", "consumer", c, buffer[c]);
		c = (c+1)%50;
		pthread_mutex_unlock(&lock);
		sleep(1);
	}
}

int main(int argc, char* argv[]){
	pthread_t t1,t2;
	pthread_mutex_init(&lock, NULL); 
    pthread_create(&t1,NULL,producer,NULL);
    pthread_create(&t2,NULL,consumer,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
}
