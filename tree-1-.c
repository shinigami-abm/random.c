#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int n;
    struct node *ls;
    struct node *rs;	    
}node;

 struct node *make_node(int num){
	 struct node *new;
	 new= (node *)malloc(sizeof(node));
	 new->n= num;
	 new->ls= NULL;
	 new->rs= NULL;
  return new;
 }

 struct node *make_tree(struct node *parent, int num){
	 struct node *this;
	 this= parent;
	if(this == NULL){
		this= make_node(num);
		return this;
	} 
	else if(this->n > num){
		 if(this->ls == NULL){
			 this->ls= make_node(num);
		 }
		 else{return make_tree(this->ls, num);}
	     } 
	     else if(this->n < num){
		    if(this->rs == NULL){
			 this->rs= make_node(num);
		    }
		    else{return make_tree(this->rs, num);}
	          }
	 return parent;
 }
 struct node *print(struct node *parent, int i){
    struct node *this;
    this= parent;
	 if(this == NULL){
		 printf("there is no tree.\n");
		 return parent;
	 }
	 else{
           if(i == 0){
	      printf("%d ",this->n);
	      i++;
	       print(this, i);
            }
	    else if(i%2 == 0){
		   if(this->rs == NULL){
			   return this->rs;
		   }
		   else{
		    this= this->rs;
			 printf("%d ",this->n);
		     i++;
		      print(this, i);
		   }  
		 }
	         else{
		     if(this->ls == NULL){
			     return this->ls;
		     }
		     else{
			 this= this->ls;
			 printf("%d ",this->n);
			 i++;
			  print(this, i);
		     }	 
		 }
	 }
 }
void right(struct node *parent) {
    if (parent == NULL)
        return;
    
    right(parent->ls);
    printf("%d ", parent->n);
    right(parent->rs);
}

 int main(){
	 int n,m,i=0;
	 struct node *parent =NULL;
         //parent->n= 99;  
	// parent->ls= NULL;
	 //  parent->rs= NULL;

	while( true ){
		printf("do you want to add number or print all the tree or exit\nadd=1;\nprint=2;\nexit=99\n");
		scanf("%d",&m);
		if(m == 99){
			return 0;
		}
		else if(m == 1){
			printf("give me a number\n");
                       scanf("%d",&n);
		       if(i == 0){
			struct node *this;
		        this= make_tree(parent, n);
			i++;
		       }
		       else{
		        make_tree(this, n);
		       }	
		     }
		     else if(m == 2){
			     print(this, 0);
			     //right(parent);
		          }
		          else{printf("wrong input\n");}
	}   



 }
