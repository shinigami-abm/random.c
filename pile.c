#include<stdio.h>
#include<stdlib.h>
int push(int stack[100], int n, int c){
   if(c == 100){
	   printf("there is no space to add a number\n");
      exit(1);
   }
   else{
	   int j=c;
	while(j != 0){
		stack[j]=stack[j-1];
		j--;
	}
	stack[0]=n;
	return c+1;
   }
}
int pop(int stack[100], int c){
	if(c == 0){
		printf("there is no numbers to pop\n");
	   exit(1);	
	}
	else{
           int temp= stack[0];
	   int j=c;
         while(j-2>=0){
		 stack[j-2]=stack[j-1];
		 j--;
	 }
	 c--;
         return temp;
	} 
}
void main(){
   int c=0;
   int stack[100];
  c=push(stack, 1, c);
  c=push(stack, 2, c);
  c=push(stack, 3, c);
  c=push(stack, 0, c);
  int j=c;
  while(j>-1){
  printf("%d\n",pop(stack, c));
  j--;
  }
}
