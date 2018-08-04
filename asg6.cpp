#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int sum=0,n=0;
void* calc(void *v)
{
int *a=(int *)v;
cout<<"a=="<<a[0]<<a[1]<<endl;
for(int i=a[0];i<a[1]&&i!=n;i++)
{
cout<<"i="<<i<<endl;
if(n%i==0)sum+=i;
}
}
int main(int argc,char *argv[])
{
int p;
p=atoi(argv[1]);
n=atoi(argv[2]);
pthread_t t[p];
int c=1,d=n/p;
for(int i=0;i<p;i++)
{
int a[2]={c,d};cout<<c<<d<<endl;
pthread_create(&t[i],NULL,calc,(void *) a);pthread_join(t[i],NULL);
c=d;d+=n/p;
}
for(int i=0;i<p;i++)
{
pthread_join(t[i],NULL);
}
cout<<"sum="<<sum;
if(sum==n)cout<<"perfect";
else cout<<"not perfect";
return 0;
}
