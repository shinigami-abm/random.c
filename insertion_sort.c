#include<stdio.h>

 void sort(int T[], int n){
  int temp;
  for(int i=0; i<n; i++){
	  for(int j= i+1; j<n; j++){
                 if(T[j]<T[i]){
			 temp= T[j];
			 for(int k= j; i<k; k--){
                             T[k]=T[k-1];
			 }
		     T[i]=temp;	 
		 }
	  }
  }
}

int main(){
	int n=6;
	int T[n];
	T[0]=1;
	T[1]=7;
	T[2]=19;
	T[3]=3;
	T[4]=5;
	T[5]=8;

   printf("{");	
   for(int i=0; i<n; i++){
	   printf(" %d ",T[i]);
   }
   printf("}\n\n");

   sort(T, n);

   printf("{");
   for(int i=0; i<n; i++){
	   printf(" %d ",T[i]);
   }
   printf("}");
}
