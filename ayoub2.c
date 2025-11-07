#include<stdio.h> 

int main(){
   int a;
   for(int i=1000; 0< i; i--){
	   if(1000%i == 0){
		   a=1000/i;
		   if(a< i){
		   printf("%d*%d=1000\n",a,i);
		   }
	   }
   }
}

