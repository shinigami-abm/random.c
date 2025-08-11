#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


int main(){

	int a,b,c,d;

    for(int i=0; i<3; i++){  // this loop makes the children
	    pid_t pid= fork();
    
         if(pid>0){ // parent process
                 

                 d=getpid();
		 int status;
		 pid_t cpid = wait(&status);

		 printf("The child %d has finshed with the PID=%d\n",i,cpid);
	 }
	 else if(pid == 0){  // child process
			sleep(1);
			_exit(0);
              }
	       else{    // if fork faild
                   printf("404\n");

	       }
   }
    printf("All the children finshed\n");
    printf("And this is the PID of the parent %d\n",d);

return 0;
}
