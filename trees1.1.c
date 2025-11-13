#include<stdio.h>
#include<stdlib.h>

typedef struct node{
   int n;
   struct node *rs;
   struct node *ls;
}node;

 struct node *print(struct node *parent, struct node *root){
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
			return print(parent, root->ls);
			return print(parent, root->rs);
		 }
	 }
 }
