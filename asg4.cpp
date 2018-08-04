#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<iostream>
int buffer[10];
int ch=0;int in=0,out=0;
using namespace std;

void *for_producer(void *a)
{
int l=0;
while(l<10){
sleep(2);
while(((in+1)%10)==out){cout<<"waiting for consumer\n";}
buffer[in]=ch;//if(ch=='Z')ch='A';
in=(in+1)%10;l++;
}
}
void *for_consumer(void *a)
{
int m=0;
while(m<10){
while(in==out){cout<<"waiting for producer\n";}
cout<<buffer[out]<<" ";
out=(out+1)%10;
m++;
}
}
int main(int argc,char* argv[])
{
pthread_t p,c;
pthread_create(&p,NULL,for_producer,NULL);
pthread_create(&c,NULL,for_consumer,NULL);
pthread_join(p,NULL);
pthread_join(c,NULL);
return 0;
}
