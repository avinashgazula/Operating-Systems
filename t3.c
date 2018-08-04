#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int *fib;

void *fibo(void *f){
	int n = *(int *)f;;
	int i;
	fib[0] = 0;
	fib[1] = 1;
	printf("%s","0 1 ");
	for(i=2;i<=n;i++){
		fib[i] = fib[i-1] + fib[i-2];
		printf("%d %s", fib[i], " ");
	}
	printf("\n");
}

int main(int argc, char* argv[]){
	pthread_t t1;
	int n = atoi(argv[1]);
	fib = malloc(n*4);
    pthread_create(&t1,NULL,fibo,&n);
    pthread_join(t1,NULL);
}
