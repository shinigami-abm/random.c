#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define t 3
typedef struct node{
  int k[2*t-1];
  struct node *c[2*t];
  bool leaf;
  int NK;// this is the number of keys in this node
}node;
void insert(struct node *parent, int num){
	if(parent == NULL){
		printf("there is no tree\n");	
	 return;	
	}
	if(parent->leaf == true){
	     if(parent->NK< 2*t-1){	
		sort(parent, num);// this function sort the table ofthe node with the new number
	      return;
	     }
	     else{
		     split(parent, num);
	      return;
	     }

	}
	else{
		int i=0;
		while(i< parent->NK && num> parent->k[i]){
			i++;
		}
		if(i == parent->NK){
			insert(parent->c[parent->NK], num);
		}
		else if(num<parent->k[i]){
			insert(parent->c[i], num);
		}
	}
}
