#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef  struct node{
 int n;
 struct node *rs;
 struct node *ls;
}node;
struct node *search(struct node *parent, int num){
	if(parent->n == num){
            return parent;
	}
	else if(parent->n > num){
	      if(parent->ls == NULL){
		      printf("there is no number such that\n");
		 return parent->ls; 
	      }
	      else{
               return search(parent->ls, num);
	      } 
	     }
	     else{
		   if(parent->rs == NULL){
			   printf("there is no number\n");
			 return parent->rs;  
		   }
		   else{
		     return search(parent->rs, num);
		   }  
	     }
}

