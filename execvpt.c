#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
   int a;
   pid_t pid =fork();

   char *stuf[][3]={
        {"ls","-l",NULL},
	{"pwd",NULL,NULL},
	{"date",NULL,NULL},
   };

   if(pid>0){ //parent process
	

	int status;
        pid_t cpid = wait(&status);
        sleep(1);
	printf("the child %d, has finshed his status %d\n",cpid,WEXITSTATUS(status));
        printf("the parent PID is %d\n ",getpid());
   }
   else if(pid == 0){ //child process
          printf("which cmd you whant\n");
	  printf("1-ls-l\n2-pwd\n3-date\n");
	  scanf("%d",&a);
	    switch(a){
            case 1:
		    execvp("ls", stuf[0]);
            break;
	    case 2:
	            execvp("pwd", stuf[1]);
            break;
	    case 3:
	            execvp("date", stuf[2]);
	    break;
            defult:
	         printf("404\n");
            break;		 
	    }

	    printf("the child PID is %d\n",getpid());
        }
        else{ // if fork faild
	      printf("404\n");
	}
return 2025;
}
