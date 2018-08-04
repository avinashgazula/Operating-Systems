#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#define noofthreads 4

struct word
{
	char s[15];
	int count;
};
int noofword;
struct word arr[200];
int sizeofhash=0;

void* increase(void* p)
{
	int i;
	char* a=(char*)p;
	int flag=0;
	for(i=0;i<sizeofhash;i++)
	{
		if(strcmp(arr[i].s,a)==0)
		{
			flag=1;
			arr[i].count++;
			break;
		}
	}
	if(flag==0)
	{
		strcpy(arr[sizeofhash].s,a);
		arr[sizeofhash].count=1;
		sizeofhash++;
	}
}
int main(int argc,char* argv[])
{
	FILE* fp;
	int i=0;
	char buffer[200][15];
	fp=fopen("a.txt","r");

	while(1)
	{
		int count=fscanf(fp,"%s",buffer[i]);
		if(count<1)
		{
			break;
		}
		i++;
	}

	noofword=i;
	pthread_t tid[noofthreads];
	int wordperthread=noofword/noofthreads;
	printf("word per thread = %d\n",wordperthread);
	int j,k;
	for(j=0;j<noofthreads;j++)
	{
		for(k=0;k<wordperthread;k++)
		{
			printf("word is %s\n",buffer[j+k]);
			pthread_create(&tid[j],NULL,increase,(void*) buffer[j*wordperthread+k]);
		}
	}
	for(j=0;j<noofthreads;j++)
	{
		pthread_join(tid[j],NULL);
	}
	printf("size of hash = %d\n",sizeofhash);
	for(j=0;j<sizeofhash;j++)
	{
		printf("%s\n",arr[j].s);
		printf("%d\n",arr[j].count);
	}
	return 0;
}