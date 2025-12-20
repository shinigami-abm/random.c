#include<stdio.h>

 void selct(int t[], int n){
    int temp,index;
	 for(int i=0; i<n; i++){
		 index=i;
		 for(int j=i; j<n; j++){
                      if(t[j]<t[index]){
                        index= j;
		      }
		 }
		 temp=t[i];
		 t[i]=t[index];
		 t[index]=temp;
	 }
 }

int main(){

  int n=7;
  int t[n];
t[0]=8;
t[1]=15;
t[2]=1;
t[3]=3;
t[4]=27;
t[5]=9;
t[6]=10;
 for(int i=0; i<n ;i++){
  printf(" %d ",t[i]);
 } 
 printf("\n");
 selct(t, n);
 for(int i=0; i<n; i++){
   printf(" %d ",t[i]);
 }
 printf("\n");

}

