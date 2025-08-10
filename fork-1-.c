#include<stdio.h>
#include<unistd.h>

#include<sys/types.h>

int main(){

  pid_t rp;

    rp=fork();
     
    if(rp>0){
		    printf("i am the parent prosses, pid=%d\n",getpid());
		    printf("and i am the child prosses, pid(=%d\n",getppid());
    } 
     else if(rp<0){
	    printf("404\n");
     }
	   else{
          printf("i am the child prosses, pid=%d\n",getpid());
	  printf("and i am the parent prosses, pid=%d\n",getppid());
           }    
}
