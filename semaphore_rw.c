#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
#include<unistd.h>

sem_t lock,wrt;
int count = 0; //no of readers

void *reader(void *f){
	do{
		sem_wait(&lock);
		count++;
		
		if(count==1) sem_wait(&wrt);
		sem_post(&lock);
		int cur = *(int*) f;
		printf("%s %d %s\n","Reader ",cur," is reading");
		sem_wait(&lock);
		count--;
		if(count==0)
		sem_post(&wrt);
		sem_post(&lock);
		sleep(1);
	}while(1);
}

void *writer(void *f){
	do{
		sleep(1);
		sem_wait(&wrt);
		int cur = *(int*) f;
		printf("%s %d %s\n","Writer ",cur," has written");
		sem_post(&wrt);
 		sleep(1);
	}while(1);
}

int main(int argc, char* argv[]){
	sem_init(&lock,0,1);
	sem_init(&wrt,0,1);
	int nr=5, nw=5,i,j,k;
        pthread_t pid[14];
    	
	int arr[]={0,1,2,3,4,5,6};
        for(i=0;i<=6;i++)
        	pthread_create(&pid[i],NULL,writer,&arr[i]);
        for(i=0;i<=6;i++)
        	pthread_create(&pid[i+7],NULL,reader,&arr[i]);
        for(i=0;i<14;i++)
        	pthread_join(pid[i],NULL);
}
