#include<stdio.h>
#include<stdlib.h>

typedef struct node{
   int n;
   struct node *rs;
   struct node *ls;
}node;

 struct node *print(struct node *parent, struct node *root){
    struct node *this;	 
	 if(parent == NULL){
		 printf("there is no tree.\n");
		 return parent;
	 }
	 else{
		 if(root == NULL){
			 return root;
		 }
		 else{
			 printf("%d\n",root->n);
			 if(root->ls == NULL){
				 return root->ls;
			 }
			 else{
				 this= root->ls;
				 printf("%d\n",this->n);
				return print(parent, this);
			 }
			 if(root->rs == NULL){
				 return root->rs;
			 }
			 else{
				 this= root->rs;
				 printf("%d\n",this->n);
				return print(parent, this); 
			 }
		 }
	 }
 }
