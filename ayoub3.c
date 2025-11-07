#include<stdio.h>
#include<math.h>


int main(){

   int x,i=0;
   int n=1;
   long long float s=0,e;

   while(e>0.0001){
	   if(i == 0 ){
		   s=1;
	   }
	   else{
	   //int n=1;
	     for(int j=1; j<i+1; j++){
                n=n*j;
	      }
	       s=s+power(x,i)/n;
	   }  
    i++;
   }
}
