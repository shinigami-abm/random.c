#include<stdio.h>
#include<stdbool.h>

int main(){
	 int n;
	 bool c=true;
	 printf("give me a number.\nn=");
	 scanf("%d",&n);
	 for(int i=2; i<n; i++){
		 if(n%i==0){
			 printf("%d is not a prime number\n",n);
			 c =false;
		 }
	 }
	 if(c != false){
            printf("%d is a prim number\n",n);
	 }   
}
