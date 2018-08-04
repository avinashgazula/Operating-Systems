#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
using namespace std;
sem_t rwmutex;
sem_t mutex;
sem_t m;
int read_count=0;
void *writer(void *param)
{
        do
        {
                sleep(1);
                sem_wait(&m);
                int* x=(int *)param;
                cout<<*x<<" writing is done"<<endl;
                sem_post(&m);
        }while(true);
}
void *reader(void *param)
{
        do
        {       sleep(1);
                sem_wait(&mutex);
                read_count++;
                if(read_count==1)
                	sem_wait(&m);
                sem_post(&mutex);
                int *x=(int *)param;
                cout<<*x<<" is reading"<<endl;
                sem_wait(&mutex);
                read_count--;
		//cout<<*x<<" complete reading \n";
                if(read_count==0)
                	sem_post(&m);
                sem_post(&mutex);
		
        }while(true);
}
int main()
{
        pthread_t pid[14];
        sem_init(&rwmutex,0,1);
        sem_init(&mutex,0,1);
        sem_init(&m,0,1);
        int arr[]={0,1,2,3,4,5,6};
        for(int i=0;i<=6;i++)
        	pthread_create(&pid[i],NULL,writer,&arr[i]);
        for(int i=0;i<=6;i++)
        	pthread_create(&pid[i+7],NULL,reader,&arr[i]);
        for(int i=0;i<14;i++)
        	pthread_join(pid[i],NULL);
        return 0;
}
