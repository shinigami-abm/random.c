#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct value{
int index;
int count;
} value;
typedef struct hash{
value v;
bool empty;
int k;
struct hash *next;
} hash;


void fill_case(int i, struct hash *node, int key, int count, int index){
 if(i == 0){
	struct hash *newnode;
	newnode= (hash *)malloc(sizeof(hash));
   newnode->empty=false;
  newnode->k=key;
 newnode->v.index=index;
  newnode->v.count=count;
   newnode->next=NULL;
     node->next=newnode;
     return;
 }
 else{
   node->empty=false;
  node->k=key;
 node->v.index=index;
  node->v.count=count;
   node->next=NULL;
 }
}


void make_map(hash t[], int n, int key, int count, int index){
  int x= key % n;
  if(t[x].empty == true){
         fill_case(99, &t[x], key, count, index);
  }
  else{
	  struct hash *node;
	  node=&t[x];
   while(node->next != NULL){
        node=node->next;
   }	   
    fill_case(0, node, key, count, index); 
  }
}


int main(){
 int n;
 printf("give me the size of the table\n");
 scanf("%d",&n);
 hash t[n];
  for(int i=0; i<n ;i++){
    t[i].empty= true;
  }
  int i=n,a,b,c;
  while(i != 0){
      printf("give me the key\n");
       scanf("%d",&a);
      printf("give me the index\n");
       scanf("%d",&b);
      printf("give me the count\n");
       scanf("%d",&c);
       make_map(t, n, a, c, b);
      i--; 
  }
  for(int i=0; i<n; i++){
   if(t[i].empty == false){	   
        printf("the key= %d\n",t[i].k);
        printf("the count= %d\n",t[i].v.count);
        printf("the last index= %d\n",t[i].v.index);
	printf("new index= %d\n",i);
	printf("\n\n");
    if(t[i].next != NULL){
     struct hash *node;
     node= t[i].next;
     while(node != NULL){
        printf(",the key= %d\n",node->k);
        printf(",the count= %d \n",node->v.count);
        printf(",the last index= %d \n",node->v.index);
	printf("\n\n");
	node=node->next;
     }
    }
   }
  }
}
