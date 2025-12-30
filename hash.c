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
  FILE *f =fopen("hash.txt", "a");	
 int n;
 printf("give me the size of the table\n");
 scanf("%d",&n);
 hash t[n];
  for(int i=0; i<n ;i++){
    t[i].empty= true;
  }
  int i=n,a,b,c;
  while(i != 0){
      printf("give me the key ");
       scanf("%d",&a);
      printf(" give me the index ");
       scanf("%d",&b);
      printf(" give me the count ");
       scanf("%d",&c);
       make_map(t, n, a, c, b);
      i--; 
      printf("\n");
  }
  for(int i=0; i<n; i++){
   if(t[i].empty == false){	   
        fprintf(f,"the key= %d\n",t[i].k);
        fprintf(f,"the count= %d\n",t[i].v.count);
        fprintf(f,"the last index= %d\n",t[i].v.index);
	fprintf(f,"new index= %d\n",i);
	fprintf(f,"\n\n");

    if(t[i].next != NULL){
     struct hash *node;
     node= t[i].next;
     while(node != NULL){
        fprintf(f,",the key= %d\n",node->k);
        fprintf(f,",the count= %d \n",node->v.count);
        fprintf(f,",the last index= %d \n",node->v.index);
	fprintf(f,"\n\n");
	node=node->next;
     }
    }
   }
  }
  fclose(f);
}
