#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>



int main(){

    pid_t pid=fork();

    if(pid>0){          // parent process
              printf("This is the parent my pid is %d\n",getpid());
	 int status;
	 pid_t spid=wait(&status);
    
              printf("The child %d has finshed his status is %d\n",spid,WEXITSTATUS(status));
         
    }

    else  if(pid == 0){  // child process
             
	    printf("I am the child my pid is %d",getpid());
	    printf(", And this is my parent pid %d\n",getppid());


          }
          
          else{    // when the fork has faild 
                   printf("404\n");
	  }






return 100;
}
