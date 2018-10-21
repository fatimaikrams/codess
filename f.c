#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int array[1000];
int csize=100;
// Example is to pass a variable from main to thread and pass some values from thread to main function
 void * TestThread(void *arg){
       int start=(int)arg;
       int end=start+csize;
int sum=0;
       for(int i=start;i<end;i++){
sum=sum+array[i];
}
return ((void*)sum);             
}
 
 
 
int main ()
{
	int status_t1[10];
	pthread_t thread_t1[10];
     for(int i=0;i<=1000;i++){
               array[i]=i;
}
         for(int i=0;i<10;i++){
         pthread_create(&thread_t1[i],NULL,TestThread,(void*)(i*100));
}     
    for(int j=0;j<10;j++){
         pthread_join(thread_t1[j],(void**) & status_t1[j]);
}
  int sum=0;
               for(int k=0;k<10;k++){
          sum=sum+status_t1[k];
}  
       sum=sum+1000;
         printf("\nValue returned By Thread %d\n", sum);
     
	return 0;
}
