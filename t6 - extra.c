#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
int SUM=0,N;
void* isperfect(void* p)
{
	int* a=(int*)p;
	int n=*a;
	printf("%d\n",n);

	if(N%n==0)
	{
		SUM+=n;
	}
}
int main(int argc,char* argv[])
{
	int i,j;
	int p=atoi(argv[argc-1]);
	pthread_t tid[p];
	N=atoi(argv[1]);
	for(i=1;i<=N/2;i+=p)
	{
		for(j=0;j<p && j+i<=N/2;j++)
		{
			int *temp=(int*)(malloc(sizeof(int)));
			*temp=i+j;
			pthread_create(&tid[j],NULL,isperfect,(void*) temp);
		}
		for(j=0;j<p && j+i<=N/2;j++)
		{
			pthread_join(tid[j],NULL);
		}
	}
	if(SUM==N)
	{
		printf("Is perfect\n");
	}
	else
	{
		printf("%d	%d \n",SUM,N);
		printf("Not a perfect \n");
	}
	return 0;
}
