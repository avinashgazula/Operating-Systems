#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void* check_prime(void* p)
{
	int* a=(int*) p;
	int n=*a;
	int i;
	int flag=0;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("%d",n);
		printf(" is a prime number.\n");
	}
}
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		exit(0);
	}
	int n;
	int i;
	n=atoi(argv[1]);
	int arr[n];
	printf("%s\n","enter elements ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);	
	}
	pthread_t tid;
	for(i=0;i<n;i++)
	{	
		pthread_create(&tid,NULL,check_prime,(void*) &arr[i]);
		pthread_join(tid,NULL);
	}
	return 0;
}










