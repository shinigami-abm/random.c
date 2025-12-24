#include<stdio.h>

 void quick(int t[], int n){
	 int p,temp,a=0,b=0,l[n],h[n];
	 if( (n-1) % 2 == 1){
            p= (n-1)/2 +1/2;
	 }
	 else{
           p= (n-1)/2;
	 }
	 for(int i=0; i<n; i++){
              if(t[i]>t[p]){
		      h[a]=t[i];
                  a++;
	      }
	      else{
                   l[b]=t[i];
		   b++;
	      }
	 }
	 temp=t[p];
      if(b != 1 && a != 1){
	 quick(l, b);
	 quick(h, a);
      }
         int  i=0;
	  while(i<a+1){
              t[i]=l[i];
	      i++;
	  }
	  t[i]=temp;
	  i++;
	  int j=0;
	  while(i<n){
            t[i]=h[j];
	    j++;
	    i++;
	  }
 }
int main(){

  int n=9;
  int t[n];
t[0]=2;
t[1]=7;
t[2]=9;
t[3]=27;
t[4]=0;
t[5]=1;
t[6]=37;
t[7]=17;
t[8]=5;
 for(int i=0; i<n ;i++){
  printf(" %d ",t[i]);
 } 
 printf("\n");
 quick(t, n);
 for(int i=0; i<n; i++){
   printf(" %d ",t[i]);
 }
 printf("\n");

}




