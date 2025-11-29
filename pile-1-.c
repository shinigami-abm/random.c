#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
  int n;
  struct node *next;
} node;
typedef struct head{
  struct node *point;
}head;

struct node *make_node(int num){
	struct node *new;
	new= (node *)malloc(sizeof(node));
	new->n= num;
	new->next= NULL;
     return new;	
}
void push(struct head *head, int num){
	if(head->point == NULL){
		head->point = make_node(num);
	}
	else{
		struct node *this;
		this= head->point;
		while(this->next != NULL){
			this=this->next;
		}
		this->next = make_node(num);
	}
}
int pop(struct head *head){
	if(head->point == NULL){
		printf("there is no numper to pop.\n");
	  return -999;	
	}
	 if(head->point->next == NULL){
		int temp= head->point->n;
		free(head->point);
		head->point = NULL;
              return temp; 
	}
		struct node *this;
		this=head->point;
		while(this->next != NULL){
                  this=this->next;
		}
		struct node *this0;
		this0= head->point;
		while(this0->next != this){
			this0=this0->next;
		}
		this0->next = NULL;
		int temp= this->n;
		free(this);
	return temp;
	
}
void main(){
  struct head *head;
  head=(struct head *)malloc(sizeof(head));
  head->point= NULL;
  push(head, 0);
  push(head, 1);
  push(head, 2);
  push(head, 3);
  push(head, 4);
  push(head, 5);
int ctr=0;
  while(ctr != -999){
	  ctr=pop(head);
     printf("%d\n",ctr);	  
  }
}
