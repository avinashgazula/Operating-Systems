#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *prime(void *f){
 int n = *(int *)f;
 int i,j;
 for(i=n; i>=1; i--){
	 int count =0;
  for(j=1; j<=n; j++){
   if(i%j==0) count++;
   if(count>2) break;
  }
  if(count==2) printf("%d %s", i, " ");
 }
 printf("%s","\n");
}

int main(int argc, char* argv[]){
	pthread_t tmin;
	int n = atoi(argv[1]);
    pthread_create(&tmin,NULL,prime,&n);
    pthread_join(tmin,NULL);
}

