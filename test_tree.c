#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
   int n;
   struct node *rs;
   struct node *ls;
}node;

void print(struct node *parent){
     if(parent->ls == NULL){
	     printf("%d\n",parent->n);
	     print();
     }
     else{
	     struct node *this;
	     this=parent->ls;
	    print(this->ls); 
	printf("%d\n",this->n);
        printf("%d\n",parent->n);
       if(parent->rs == NULL){
	       return;
       }
       else{
	       print(parent->rs);
	       printf("%d\n",parent->rs->n);

       }
     }
}
