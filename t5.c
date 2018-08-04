#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *prime(void *f){
 int n = *(int *)f;
 int j,count = 0;
  for(j=1; j<=n; j++){
   if(n%j==0) count++;
   if(count>2) break;
  }
  if(count==2) printf("%d ", n);
  return NULL;
  //pthread_exit(0);
 
}

int main(int argc, char* argv[]){
	
	int a[100],n = atoi(argv[1]);
	pthread_t t[100],tt;
	int i;
	for(i=n;i>=1;i--){
		a[i]=i;pthread_create(&t[i],NULL,prime,&a[i]);
	}
	for(i=n;i>=1;i--) pthread_join(t[i],NULL);
	printf("\n");
}
 

