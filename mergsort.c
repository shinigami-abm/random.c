#include<stdio.h>
void merge(int l[], int r[], int t[], int sl, int sr, int st){
        int i=0,j=0,k=0;
	while(j<sl && k<sr){
          if(l[j] < r[k]){
		 t[i] = l[j];
		  i++;
		  j++;
	  }
	  else{
            t[i]=r[k];
	    i++;
	    k++;
	  }
	}
	if(j == sl){
             t[i]=r[k];
	     i++;
	     k++;
	}
	else{
          t[i]=l[j];
	  j++;
	  i++;
	}
}
void divaide(int t[], int n){
  if(n <= 1){
     return;
  }
  int p;
  if( (n-1) % 2 == 1){
      p= (n-1);
     p=p/2 +0.5;
   }
   else{
     p= (n-1);
     p=p/2;
   }
   //p=p+1;
   int l[p+1],r[n-(p+1)];
   int j=0,k=0,o=0;
   while(j<n){
        if(j > p){
          r[k]=t[j];
	  k++;
	}
	else{
          l[o]=t[j];
	  o++;
	}
	j++;
   }
    for(int h=0; h<n-(p+1) ;h++){
  printf(" %d ",r[h]);
 } 
 printf("\n");
 for(int h=0; h<p+1 ;h++){
  printf(" %d ",l[h]);
 } 
 printf("\n");

   divaide(l, p+1);
   divaide(r , n-(p+1));
   merge(l, r, t, (p+1), n-(p+1), n);
}
int main(){

  int n=8;
  int t[n];
t[0]=15;
t[1]=2;
t[2]=44;
t[3]=3;
t[4]=0;
t[5]=1;
t[6]=9;
t[7]=27;
//t[8]=99;
 for(int i=0; i<n ;i++){
  printf(" %d ",t[i]);
 } 
 printf("\n");
 divaide(t, n);
 for(int i=0; i<n; i++){
   printf(" %d ",t[i]);
 }
 printf("\n");

}

