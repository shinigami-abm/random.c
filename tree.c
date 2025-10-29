#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int n;
    struct node *ls;
    struct node *rs;
}node;


   struct node *new_node(int m){
	   struct node *new= (node *)malloc(sizeof(node));
	   new->n= m;
	   new->ls= NULL;
	   new->rs= NULL;
     return new;	   
   }
   void link_node (struct node *parent, struct node *lson, struct node *rson){

	   parent->ls= lson;
	   parent->rs= rson;
   }
  void fill(struct node *parent, int i){

	  while(i != 3){
		  link_node(new_node(i), new_node(2*i+1), new_node(2*i+2));
		  i++;
	  }
  }
  int print(struct node *head){
	  struct node *this= head;
	  if(head->ls == NULL || head->rs == NULL){return 0;}
	  else{
		  printf("%d.\n",this->n);
		  return print(this->ls) + print(this->rs);
	  }
  }

  int main(){
    int i=0;
    struct node *h;
    fill(h, i);
    print(h);

  }
