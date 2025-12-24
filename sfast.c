#include<stdio.h>
#include<stdlib.h>
 void sfast(int t[], int n){
   if(n<=1){return;}
  int p;
  if( (n-1)%2==1){
      p=n-1;
      p=p/2+0.5;
  }
  else{
   p=n-1;
   p=p/2;
  }
 //printf("%d.\n",p);
   int a=0,b=0,l[n],h[n],i=0,j=0,temp;
   while(i<n){
     if(t[p]<t[i]){
           h[a]=t[i];
	    a++;  
     }
     else if(t[p]>t[i]){
         l[b]=t[i];
	  b++;
     }
    i++;
   } 
   sfast(l, b);
   sfast(h ,a);
     i=0;
     temp=t[p];
     while(i<n){
             if(i<b){
                 t[i]=l[i];
	     }
	     else if(i>b){
		     t[i]=h[j];
		     j++;	     
	          } 
	 i++;    
     }
     t[b]=temp;
}
int main(){
  //sfast(t, n);
  int n=6;
  int t[n];
t[0]=25;
t[1]=5;
t[2]=55;
t[3]=35;
t[4]=65;
t[5]=15;
 for(int i=0; i<n ;i++){
  printf(" %d ",t[i]);
 } 
 printf("\n");
 sfast(t, n);
 for(int i=0; i<n; i++){
   printf(" %d ",t[i]);
 }
 printf("\n");
}

