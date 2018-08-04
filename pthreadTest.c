/*#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
// A normal C function that is executed as a thread when its name
// is specified in pthread_create()
void *myThreadFun(void *vargp)
{
    sleep(1);
    printf("Printing GeeksQuiz from Thread \n");
    return NULL;
}
  
int main()
{
    pthread_t tid;
    printf("Before Thread\n");
    pthread_create(&tid, NULL, myThreadFun, NULL);
    pthread_exit(NULL);
    printf("After Thread\n");
    exit(0);
}*/







#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
// Let us create a global variable to change it in threads
int g = 0;
 
// The function to be executed by all threads
void *myThreadFun(void *vargp)
{
    // Store the value argument passed to this thread
    int myid = *(int*)vargp;
 
    // Let us create a static variable to observe its changes
    static int s = 0;
 
    // Change static and global variables
    ++s; ++g;
 
    // Print the argument, static and global variables
    printf("Thread ID: %d, Static: %d, Global: %d\n", myid, ++s, ++g);
}

void *f1(void *i){
	printf("%s %d\n","f1",*(int *)i);
}

void *f2(void *i){
	printf("%s %d\n","f2",*(int *)i);
}
	
 
int main()
{
    int i;
    pthread_t tid;
    pthread_t t1, t2;
 
    // Let us create three threads
    for (i = 0; i < 3; i++){
        pthread_create(&t1, NULL, f1, &i);
        pthread_join(t1,NULL);
        pthread_create(&t2, NULL, f2, &i);
        pthread_join(t2,NULL);
	}
    
    pthread_exit(NULL);
    return 0;
}
