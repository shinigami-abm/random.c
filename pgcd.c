#include<stdio.h>


int pgcd(int a,int b){
   if(a==b){return a;}

   else if (a<b){return pgcd(a,b-a);}

   else {return pgcd (a-b,b);}
}

int main(){
   int a,b;

  scanf ("%d",&a);
  scanf("%d",&b);

  printf("PGCD(%d,%d)=%d\n",a,b,pgcd(a,b));

}
