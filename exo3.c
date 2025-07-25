#include<stdio.h>


int calculera (int n){    

   int s=0,c=0;

   for(int i=1;i<n+1;i++){
	   for(int j=1;j<i+1;i++){
		   if(i%j==0){c++;}
	   }
	   if(c<3){
		   s=s+i*i;
	   }
   }

return s;
}


int main(){

  int n;
   
      printf("Give me a vlue for n\n");
      scanf("%d",&n);


      calculera (n);


}

