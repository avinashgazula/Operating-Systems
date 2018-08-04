#include<bits/stdc++.h>
#include<pthread.h>
#include<wait.h>
#include<unistd.h>
#include<semaphore.h>
using namespace std;
sem_t mutex;
sem_t S[5];
int state[5]={1};
int phil_num[5]={0,1,2,3,4};
void test(int);
void pickup(int);
void putdown(int);
void *philosopher(void *param)
{
        while(true)
        {
                int *i=(int *)param;
                sleep(1);
                pickup(*i);
                sleep(0);
                putdown(*i);
        }
}
void test(int ph_num)
{
        if(state[ph_num]==2&&state[(ph_num+1)%5]!=3&&state[(ph_num+4)%5]!=3)
        {
                state[ph_num]=3;
                sleep(2);
                cout<<ph_num+1<<" is Eating"<<endl;
                sem_post(&S[ph_num]);
        }
}
void pickup(int ph_num)
{
        sem_wait(&mutex);
        state[ph_num]=2;
        cout<<ph_num+1<<" is Hungry"<<endl;
        test(ph_num);
        sem_post(&mutex);
        sem_wait(&S[ph_num]);
        sleep(1);
}
void putdown(int ph_num)
{
        sem_wait(&mutex);
        state[ph_num]=1;
        test((ph_num+4)%5);
        test((ph_num+1)%5);
        cout<<ph_num+1<<" is Thinking"<<endl;
        sem_post(&mutex);
}
int main()
{
        pthread_t tid[5];
        void *r;
        int value;
        sem_init(&mutex,0,1);
        for(int i=0;i<5;i++)
        sem_init(&S[i],0,1);
        for(int i=0;i<5;i++)
        {
                pthread_create(&tid[i],NULL,philosopher,&phil_num[i]);
                cout<<i+1<<" is Thinking"<<endl;
        }
        for(int i=0;i<5;i++)
        {
                pthread_join(tid[i],&r);
        }
        return 0;
}
