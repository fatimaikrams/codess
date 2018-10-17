#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
int pid=fork();
if(pid>0){
printf("parent");
}
if(pid==0){
sleep(30);
printf("child");
}
return 0;
}

