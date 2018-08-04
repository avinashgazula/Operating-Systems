#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int min = 9999;
int max = -1;
double avg = 0;

struct num{
 int count;
 int *no;
};

void *minimum(void *f){
 struct num n = *(struct num*)f;
 int i;
 for(i=0; i<n.count; i++){
  if(n.no[i]<min) min = n.no[i];
 }
}

void *maximum(void *f){
 struct num n = *(struct num*)f;
 int i;
 for(i=0; i<n.count; i++){
  if(n.no[i]>max) max = n.no[i];
 }
}

void *average(void *f){
 struct num n = *(struct num*)f;
 int i;
 int sum=0;
 for(i=0; i<n.count; i++){
  sum+=n.no[i];
 }
 avg = sum/n.count;
}

int main(int argc, char *argv[]){
 pthread_t tmin;
 pthread_t tmax;
 pthread_t tavg;
 struct num n;
 n.count = argc - 1;
 n.no = malloc((n.count)*4);
 int i;
 for(i=0; i<n.count; i++)
  n.no[i] = atoi(argv[i+1]);
 pthread_create(&tmin,NULL,minimum,&n);
 pthread_join(tmin,NULL);
 pthread_create(&tmax,NULL,maximum,&n);
 pthread_join(tmax,NULL);
 pthread_create(&tavg,NULL,average,&n);
 pthread_join(tavg,NULL);
 printf("%s %d\n","Minimum :", min);
 printf("%s %d\n","maximum :", max);
 printf("%s %.2f\n","average :", avg);
 return 0;
}
