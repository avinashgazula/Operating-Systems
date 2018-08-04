#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
int buffer[20];
sem_t full;
sem_t empty;
sem_t mutex;
int in=0,out=0;
void* produce(void* x)
{
    while(1)
    {
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in]=rand()%100;
        printf("produced %d \n",buffer[in]);
        in=(in+1)%20;
        sleep(1);
        sem_post(&mutex);
        sem_post(&full);
    }
}
void* consume(void* y)
{
    while(1)
    {
        sem_wait(&full);
        sem_wait(&mutex);
        printf("consumed %d \n",buffer[out]);
        out=(out+1)%20;
        sleep(0.8);
        sem_post(&mutex);
        sem_post(&empty);
    }
}
int main()
{
    sem_init(&full,0,0);
    sem_init(&empty,0,20);
    sem_init(&mutex,0,1);
    pthread_t pid,cid;
    pthread_create(&pid,NULL,produce,NULL);
    pthread_create(&cid,NULL,consume,NULL);
    pthread_join(pid,NULL);
    pthread_join(cid,NULL);
}