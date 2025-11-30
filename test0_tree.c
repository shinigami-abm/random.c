#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node {
   int n;
   struct node *rs;
   struct node *ls;
}node;
int  show(struct node *parent){
   if(parent->ls == NULL){
	   printf("%d\n",parent->n);
	     if(parent->rs == NULL){
		     return 0;
	     }
	     else{
		     return show(parent->rs);
	     }
   }
   else{
	   return show(parent->ls);
	   printf("%d\n",parent->n);
	   if(parent->rs == NULL){
		   return 0;
	   }
	   else{
		   printf("%d\n",parent->rs->n);
	   }
   }
}
