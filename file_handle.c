#include<stdio.h>
#include<stdlib.h>

typedef struct student{
 char FN[100];
 int age;
 int ID;
 float avr;
 struct student *next;
}student;

struct student *make_new_node(char n[100], int a, int id, float m){
       struct student *new;
       new= (student *)malloc(sizeof(student));
       for(int i=0; i<100; i++){
           new->FN[i]=n[i];
       }
       new->age=a;
       new->ID=id;
       new->avr=m;
       new->next= NULL;
  return new;     
}
void fill(struct student *s){
FILE *f;	
 f=fopen("test.txt", "a");
   fprintf(f,"%s",s->FN);
   fprintf(f," %d",s->age);
   fprintf(f," %d",s->ID);
   fprintf(f," %f",s->avr);
   fprintf(f,"\n");
 fclose(f);
}
 struct student *list(struct student *parent,char n[100], int a, int id, float m){
   if(parent == NULL){
	   parent = make_new_node(n, a, id, m);
	   return parent; 
   }
   struct student *this;
   this= parent;
   while(this->avr < m && this->next != NULL){
     this=this->next;	
   }
   if(this->avr < m){
       struct student *ns;
       ns= make_new_node(n, a, id, m);
       ns->next=this->next;
       this->next= ns;
       return parent;
   }
   if(this->next == NULL){
	   this->next= make_new_node(n, a, id, m);
   }
 }
void fill_file(struct student *parent){
 while(parent != NULL){
  fill(parent);
  parent=parent->next;
 }
 return;
} 
void read_file(struct student *parent){
FILE *Z;
char ame[100];
int age,id;
float avr;
 Z= fopen("test.txt", "r");
 if(Z == NULL){
	  return;
 }
 else{
  while(fscanf(Z, "%s %d %d %f", ame, &age, &id, &avr) != EOF){
    list(parent, ame, age, id, avr);
  }
 }
 fclose(Z);
}


int main(){
  struct student *s;
  s= NULL;
 char n[100];
 int age,id,ctr=0;
 float avr;
 while(ctr == 0){
printf("Give me your full name.\n");
scanf("%s",n);
printf("Give me you age.\n");
scanf("%d",&age);
printf("Give me your id.\n");
scanf("%d",&id);
printf("Give me your average.\n");
scanf("%f",&avr);
scanf("%d",&ctr);
s= list(s, n, age, id, avr);
}
fill_file(s);
return -999;
}
