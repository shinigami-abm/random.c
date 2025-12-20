#include<stdio.h>

 void bubble(int t[], int n){
	 int  temp;
	 for(int i=n-1; -1<i; i--){
            for(int j=0; j<i; j++){
              if(t[j]>t[j+1]){
                temp=t[j];
		t[j]=t[j+1];
		t[j+1]=temp;
	      }
	    }
	 }
 }

int main(){

  int n=7;
  int t[n];
t[0]=1;
t[1]=17;
t[2]=3;
t[3]=25;
t[4]=9;
t[5]=7;
t[6]=5;
 for(int i=0; i<n ;i++){
  printf(" %d ",t[i]);
 } 
 printf("\n");
 bubble(t, n);
 for(int i=0; i<n; i++){
   printf(" %d ",t[i]);
 }
 printf("\n");

}












